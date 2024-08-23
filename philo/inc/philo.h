/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:12:57 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/22 14:57:07 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

# define EAT "is eating 🥘\n"
# define SLEEP "is sleeping 😴\n"
# define THINK "is thinking 🤔\n"
# define FORK "has taken a fork 🍴\n"
# define DIE "died 🪦😵\n"
# define FULL "ALL PHILOSOPHERS ARE FULL! 😋\n"

typedef struct s_table
{
	/* data */
}t_table;

typedef struct s_philo
{
	/* data */
}t_philo;


/*error_handling*/
int		ft_exit(char *msg);

/*utils*/
long	ft_atoi(char *nbr);
int		is_number(char *str);

#endif 