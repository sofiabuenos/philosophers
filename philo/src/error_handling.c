/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:02:40 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/11/18 17:45:57 by sbueno-s         ###   ########.fr       */
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

void	free_structs()