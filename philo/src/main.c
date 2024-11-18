/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:59 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/23 15:46:49 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		ft_exit("Wrong number of arguments");
	if (!check_param(av))
		return (EXIT_FAILURE);
	init_structs();
	return (0);
}

