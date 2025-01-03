/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:25:07 by sbueno-s          #+#    #+#             */
/*   Updated: 2025/01/03 19:28:08 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *s)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

void	print_msg(t_philo *philos, char *msg)
{
	pthread_mutex_lock(philos->print_lock);
	if (!no_philos_dead(philos))
		printf("%zu %d %s",
			get_time() - philos->manager->start, philos->id, msg);
	pthread_mutex_unlock(philos->print_lock);
}
