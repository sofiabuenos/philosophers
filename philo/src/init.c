/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:59:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/09/07 14:28:57 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philos(t_manager *manager, t_philo *philos)
{
	int	i;
	int	id;

	i = 0;
	while (i < manager->nbr_philo)
	{
		id = i + 1;
		philos[i].id = id;
		philos[i].is_eating = false;
		philos[i].just_died = false;
		philos[i].manager = manager;
		philos[i].r_fork = &manager->forks[i];
		philos[i].l_fork = &manager->forks[((i + 1) % manager->nbr_philo)];
		philos[i].nbr_meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].death_lock = &manager->death_lock;
		philos[i].print_lock = &manager->print_lock;
		philos[i].meal_lock = &manager->meal_lock;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_forks(t_manager *manager)
{
	int	i;

	manager->forks = malloc(sizeof(pthread_mutex_t) * manager->nbr_philo);
	if (!manager->forks)
	{
		ft_putstr_fd(2, "malloc faliure\n");
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < manager->nbr_philo)
	{
		if (pthread_mutex_init(&manager->forks[i], NULL) != 0)
		{
			ft_putstr_fd(2, "pthread_mutex_init failure\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	init_manager(t_manager *manager, t_philo *philos, int ac, char **av)
{
	manager->nbr_philo = ft_atoi(av[1]);
	manager->time_to_die = ft_atoi(av[2]);
	manager->time_to_eat = ft_atoi(av[3]);
	manager->time_to_sleep = ft_atoi(av[4]);
	manager->philos = philos;
	if (ac == 6)
		manager->nbr_must_eat = ft_atoi(av[5]);
	else
		manager->nbr_must_eat = -1;
	manager->philo_is_dead = false;
	manager->start = get_time();
	pthread_mutex_init(&manager->death_lock, NULL);
	pthread_mutex_init(&manager->print_lock, NULL);
	pthread_mutex_init(&manager->meal_lock, NULL);
}

int	init_structures(t_manager *manager, t_philo *philos, int ac, char **av)
{

	init_manager(manager, philos, ac, av);
	if (init_forks(manager))
		return (EXIT_FAILURE);
	if (init_philos(manager, philos))
		return (EXIT_FAILURE);
	print_structures(manager, philos);
	return (0);
}
