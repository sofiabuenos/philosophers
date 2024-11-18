/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:07:47 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/11/18 15:58:59 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_msg(t_philo *philos, char *msg)
{
	pthread_mutex_lock(philos->print_lock);
	if (!no_philos_dead(philos))
		printf("%zu %d %s", get_time() - philos->manager->start, philos->id, msg);
	pthread_mutex_unlock(philos->print_lock);
}

void	eat(t_philo	*philos)
{
	pthread_mutex_lock(philos->r_fork);
	print_msg(philos, FORK);
	pthread_mutex_lock(philos->l_fork);
	print_msg(philos, FORK);
	pthread_mutex_lock(philos->meal_lock);
	philos->nbr_meals_eaten++;
	philos->is_eating = true;
	philos->last_meal = get_time();
	pthread_mutex_unlock(philos->meal_lock);
	print_msg(philos, EAT);
	ft_usleep(philos->manager->time_to_eat);
	pthread_mutex_lock(philos->meal_lock);
	philos->is_eating = false;
	pthread_mutex_unlock(philos->meal_lock);
	pthread_mutex_unlock(philos->r_fork);
	pthread_mutex_unlock(philos->l_fork);
}

void	nap(t_philo *philos)
{
	print_msg(philos, SLEEP);
	ft_usleep(philos->manager->time_to_sleep);
}

void	think(t_philo *philo)
{
	size_t	t_think;

	t_think = (philo->manager->time_to_eat * 2) - philo->manager->time_to_sleep;
	print_msg(philo, THINK);
	if (philo->manager->nbr_philo % 2 != 0)
		ft_usleep(t_think * 0.42);
}

// void	think(t_philo *philos)
// {
// 	size_t	free_time;
// 	size_t	think_time;
// 	size_t	min_think_time;

// 	min_think_time = 420;
// 	free_time = (philos->manager->time_to_die - philos->manager->time_to_eat
// 			- philos->manager->time_to_sleep);
// 	if (free_time <= 0)
// 		think_time = min_think_time;
// 	else
// 		think_time = free_time / 2;
// 	print_msg(philos, THINK);
// 	ft_usleep(think_time);
// }

void	*philos_routine(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;

	if (philos->id % 2 == 0 && philos->manager->nbr_philo % 2 == 0)
		ft_usleep(1);
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
