/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:59:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/28 15:36:12 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_manager(t_manager *manager, int ac, char **av)
{
	manager->nbr_philo = ft_atoi(av[1]);
	manager->time_to_die = ft_atoi(av[2]);
	manager->time_to_eat = ft_atoi(av[3]);
	manager->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		manager->nbr_must_eat = ft_atoi(av[5]);
	else
		manager->nbr_must_eat = -1;
	manager->philo_is_dead = false;
	manager->start = 
}

void	init_philo(t_philo *philo)
{
	
}
