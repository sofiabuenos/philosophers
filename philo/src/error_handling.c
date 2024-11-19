/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:02:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/11/19 18:02:16 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	mutex_destroy(t_manager *manager)
{
	int	i;

	pthread_mutex_destroy(&manager->death_lock);
	pthread_mutex_destroy(&manager->print_lock);
	i = -1;
	while (i < manager->nbr_philo)
		pthread_mutex_destroy(&manager->forks[i]);
}

void	free_struct(t_manager *manager, t_philo *philos)
{
	if (philos)
		free(philos);
	if (manager)
	{
		mutex_destroy(manager);
		free(manager);
	}
}
