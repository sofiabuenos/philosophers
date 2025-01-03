/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:29:14 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/01/03 19:29:39 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* prints t_philo*/
void	print_philo(t_philo *philos)
{
	printf("Philos ID: %d\n", philos->id);
	printf("Right Fork ID: %p\n", philos->r_fork);
	printf("Left Fork ID: %p\n", philos->l_fork);
	printf("Number of Meals Eaten: %d\n", philos->nbr_meals_eaten);
	printf("Last Meal Time: %ld\n", philos->last_meal);
	printf("Thread ID: %p\n", (void *)philos->thread);
	printf("Dead Lock: %p\n", (void *)philos->death_lock);
	printf("Manager ptr: %p\n", (void *)philos->manager);
}

/* prints t_manager */
void	print_manager(t_manager *manager)
{
	printf("Number of Philosophers: %d\n", manager->nbr_philo);
	printf("Time to Die: %zu\n", manager->time_to_die);
	printf("Time to Eat: %zu\n", manager->time_to_eat);
	printf("Time to Sleep: %zu\n", manager->time_to_sleep);
	printf("Number of Times Each Philosopher Must Eat: %d\n",
		manager->nbr_must_eat);
	printf("Forks: %p\n", (void *)manager->forks);
	printf("Philosophers arr: %p\n", (void *)manager->philos);
}

/* prints t_manager and t_philo*/
void	print_structures(t_manager *manager, t_philo *philos)
{
	int	i;

	printf("\nManager Structure:\n");
	print_manager(manager);
	printf("\nPhilo Structure:\n");
	i = -1;
	while (++i < manager->nbr_philo)
	{
		print_philo(&philos[i]);
		printf("---------------------\n");
	}
}
