/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:02:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/11/19 18:56:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	mutex_destroy(t_manager *manager)
{
	int	i;

	pthread_mutex_destroy(&manager->death_lock);
	pthread_mutex_destroy(&manager->print_lock);
	i = 0;
	while (i < manager->nbr_philo)
	{
		pthread_mutex_destroy(&manager->forks[i]);
		i++;
	}
}

void	free_struct(t_philo *philos)
{
	if (philos->manager->forks)
		free(philos->manager->forks);
	if (philos)
		free(philos);
}
