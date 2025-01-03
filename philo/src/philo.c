/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:33:19 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/01/03 19:16:46 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_param(char **av)
{
	if (atoi(av[1]) <= 0 || !is_number(av[1]))
		return (write(2, "Wrong number_of_philosophers\n", 30), 1);
	if (atoi(av[2]) <= 0 || !is_number(av[2]))
		return (write(2, "Wrong time_to_die\n", 19), 1);
	if (atoi(av[3]) <= 0 || !is_number(av[3]))
		return (write(2, "Wrong time_to_eat\n", 19), 1);
	if (atoi(av[4]) <= 0 || !is_number(av[4]))
		return (write(2, "Wrong time_to_sleep\n", 21), 1);
	if (av[5] && (atoi(av[5]) <= 0 || !is_number(av[5])))
		return (write(2, "Wrong num_of_times_philosophers_must_eat\n", 42), 1);
	return (0);
}
