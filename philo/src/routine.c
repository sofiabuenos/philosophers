/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:07:47 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/01/03 19:30:52 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->r_fork);
		print_msg(philos, FORK);
		pthread_mutex_lock(philos->l_fork);
		print_msg(philos, FORK);
	}
	else
	{
		pthread_mutex_lock(philos->l_fork);
		print_msg(philos, FORK);
		pthread_mutex_lock(philos->r_fork);
		print_msg(philos, FORK);
	}
}

void	eat(t_philo	*philos)
{
	take_forks(philos);
	pthread_mutex_lock(philos->meal_lock);
	philos->nbr_meals_eaten++;
	philos->is_eating = true;
	philos->last_meal = get_time();
	pthread_mutex_unlock(philos->meal_lock);
	print_msg(philos, EAT);
	ft_usleep(philos, philos->manager->time_to_eat);
	pthread_mutex_lock(philos->meal_lock);
	philos->is_eating = false;
	pthread_mutex_unlock(philos->meal_lock);
	pthread_mutex_unlock(philos->r_fork);
	pthread_mutex_unlock(philos->l_fork);
}

void	nap(t_philo *philos)
{
	print_msg(philos, SLEEP);
	ft_usleep(philos, philos->manager->time_to_sleep);
}

void	think(t_philo *philo)
{
	size_t	t_think;

	t_think = (philo->manager->time_to_eat * 2) - philo->manager->time_to_sleep;
	print_msg(philo, THINK);
	if (philo->manager->nbr_philo % 2 != 0)
		ft_usleep(philo, t_think * 0.42);
}

/*if nbr of philos are even -> odds eat first*/
void	*philos_routine(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	if (philos->id % 2 == 0 && philos->manager->nbr_philo % 2 == 0)
		ft_usleep(philos, 1);
	else if (philos->id % 2 != 0 && philos->manager->nbr_philo % 2 != 0)
		think(philos);
	while (!no_philos_dead(philos))
	{
		eat(philos);
		nap(philos);
		think(philos);
	}
	return (ptr);
}
