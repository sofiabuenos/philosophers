/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:22:31 by sofiabueno        #+#    #+#             */
/*   Updated: 2025/01/03 19:25:36 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	ft_atoi(char *nbr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		res = res * 10;
		res = res + (*nbr - '0');
		nbr++;
	}
	return (res * sign);
}

int	is_number(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if ((str[0] == '-' || str[0] == '+'))
			i++;
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_philo *philos, size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds && !no_philos_dead(philos))
		usleep(500);
	return (0);
}
