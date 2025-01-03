/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:04 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/01/03 19:16:59 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	no_philos_dead(t_philo *philos)
{
	pthread_mutex_lock(philos->death_lock);
	if (philos->manager->philo_is_dead == true)
		return (pthread_mutex_unlock(philos->death_lock), 1);
	pthread_mutex_unlock(philos->death_lock);
	return (0);
}

int	check_full(t_philo *philos)
{
	int	philos_full;
	int	i;

	if (philos->manager->nbr_must_eat == -1)
		return (0);
	philos_full = 0;
	i = -1;
	while (++i < philos->manager->nbr_philo)
	{
		pthread_mutex_lock(philos->meal_lock);
		if (philos[i].nbr_meals_eaten >= philos->manager->nbr_must_eat)
			philos_full++;
		pthread_mutex_unlock(philos->meal_lock);
	}
	if (philos_full == philos->manager->nbr_philo)
	{
		print_msg(philos, FULL);
		pthread_mutex_lock(philos->death_lock);
		philos->manager->philo_is_dead = true;
		pthread_mutex_unlock(philos->death_lock);
		return (1);
	}
	return (0);
}

int	philo_died(t_philo *philos)
{
	size_t	time_since_last_meal;

	pthread_mutex_lock(philos->meal_lock);
	time_since_last_meal = get_time() - philos->last_meal;
	if (time_since_last_meal > philos->manager->time_to_die
		&& philos->is_eating == false)
	{
		pthread_mutex_unlock(philos->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->meal_lock);
	return (0);
}

int	check_death(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->manager->nbr_philo)
	{
		if (philo_died(&philos[i]))
		{
			print_msg(&philos[i], DIED);
			pthread_mutex_lock(philos[i].death_lock);
			philos[i].manager->philo_is_dead = true;
			pthread_mutex_unlock(philos[i].death_lock);
			return (1);
		}
	}
	return (0);
}

void	one_philo(t_manager *manager, t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, FORK);
	ft_usleep(philo, manager->time_to_die);
	print_msg(philo, DIED);
	pthread_mutex_unlock(philo->r_fork);
}
