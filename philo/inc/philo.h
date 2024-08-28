/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:12:57 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/28 15:35:47 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# define EAT "is eating 🥘\n"
# define SLEEP "is sleeping 😴\n"
# define THINK "is thinking 🤔\n"
# define FORK "has taken a fork 🍴\n"
# define DIE "died 🪦😵\n"
# define FULL "ALL PHILOSOPHERS ARE FULL! 😋\n"

typedef struct s_manager
{
	int				nbr_philo;
	int				nbr_must_eat;
	bool			philo_is_dead;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
}					t_manager;

typedef struct s_philo
{
	t_manager		*manager;
	pthread_t		thread;
	int				id;
	int				r_fork_id;
	int				l_fork_id;
	int				nbr_meals_eaten;
	size_t			last_meal;
	pthread_mutex_t	*dead_lock;
}				t_philo;

/*error_handling*/
int		ft_exit(char *msg);

/*utils*/
long	ft_atoi(char *nbr);
int		is_number(char *str);
void	*ft_memset(void *s, int c, size_t n);

#endif 