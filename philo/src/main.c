/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:59 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/11/19 19:16:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


// Função para imprimir a estrutura t_philo
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

// Função para imprimir a estrutura t_manager
void	print_manager(t_manager *manager)
{
	printf("Number of Philosophers: %d\n", manager->nbr_philo);
	printf("Time to Die: %zu\n", manager->time_to_die);
	printf("Time to Eat: %zu\n", manager->time_to_eat);
	printf("Time to Sleep: %zu\n", manager->time_to_sleep);
	printf("Number of Times Each Philosopher Must Eat: %d\n", manager->nbr_must_eat);
	printf("Forks: %p\n", (void *)manager->forks);
	printf("Philosophers arr: %p\n", (void *)manager->philos);
}

// Função para imprimir as estruturas t_manager e t_philo
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

/*checks if the parameters are positive numbers*/
int	check_param(char **av)
{
	if (atoi(av[1]) <= 0 || !is_number(av[1]))
		return (ft_putstr_fd(2, "Wrong number_of_philosophers\n"), 1);
	if (atoi(av[2]) <= 0 || !is_number(av[2]))
		return (ft_putstr_fd(2, "Wrong time_to_die\n"), 1);
	if (atoi(av[3]) <= 0 || !is_number(av[3]))
		return (ft_putstr_fd(2, "Wrong time_to_eat\n"), 1);
	if (atoi(av[4]) <= 0 || !is_number(av[4]))
		return (ft_putstr_fd(2, "Wrong time_to_sleep\n"), 1);
	if (av[5] && (atoi(av[5]) <= 0 || !is_number(av[5])))
		return (ft_putstr_fd(2, "Wrong num_of_times_philo_must_eat\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_manager	manager;
	t_philo		*philos;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd(2, "Wrong number of arguments, must have 5 or 6\n");
		return (EXIT_FAILURE);
	}
	if (check_param(av))
		return (EXIT_FAILURE);
	philos = malloc(sizeof(t_philo) * (ft_atoi(av[1])));
	if (!philos)
	{
		ft_putstr_fd(2, "malloc faliure\n");
		return (EXIT_FAILURE);
	}
	if (init_structures(&manager, philos, ac, av))
		return (free_struct(philos), EXIT_FAILURE);
	if (manager.nbr_philo == 1)
		one_philo(&manager, philos);
	else
		if (create_threads(&manager, philos))
			return (free_struct( philos), EXIT_FAILURE);
	free_struct(philos);
	return (0);
}

