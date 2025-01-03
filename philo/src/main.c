/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:59 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/01/03 19:29:54 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
			return (free_struct(philos), EXIT_FAILURE);
	free_struct(philos);
	return (0);
}
