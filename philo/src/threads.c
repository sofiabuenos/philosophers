/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:38:47 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/01/03 19:23:33 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*check_status(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (check_full(philos) || check_death(philos))
			break ;
	}
	return (ptr);
}

int	create_threads(t_manager *manager, t_philo *philos)
{
	pthread_t	checker;
	int			i;

	if (pthread_create(&checker, NULL, &check_status, philos))
		mutex_destroy(manager);
	i = -1;
	while (++i < manager->nbr_philo)
	{
		if (pthread_create(&philos[i].thread, NULL,
				&philos_routine, &philos[i]))
			mutex_destroy(manager);
	}
	if (pthread_join(checker, NULL))
		mutex_destroy(manager);
	i = -1;
	while (++i < manager->nbr_philo)
		if (pthread_join(philos[i].thread, NULL))
			mutex_destroy(manager);
	return (0);
}
