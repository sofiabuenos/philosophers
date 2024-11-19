/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:12:57 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/11/19 18:02:34 by sofiabueno       ###   ########.fr       */
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
# define DIED "died 🪦😵\n"
# define FULL "ALL PHILOSOPHERS ARE FULL! 😋\n"

// # define EAT "is eating\n"
// # define SLEEP "is sleeping\n"
// # define THINK "is thinking\n"
// # define FORK "has taken a fork\n"
// # define DIED "died\n"
// # define FULL "ALL PHILOSOPHERS ARE FULL!\n"

/*Struct philo represents each philosopher and saves
**operational info and permitions*/
typedef struct s_philo
{
	int					id;
	int					nbr_meals_eaten;
	bool				is_eating;
	bool				just_died;
	size_t				last_meal;
	pthread_t			thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*death_lock;
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*meal_lock;
	struct s_manager	*manager;
}						t_philo;

/*the manager struct saves the general information of the program
 *including the given parameters, starting time, life status and mutexes*/
typedef struct s_manager
{
	int				nbr_philo;
	int				nbr_must_eat;
	bool			philo_is_dead;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
}					t_manager;

/*error_handling*/
void	mutex_destroy(t_manager *manager);
void	free_struct(t_manager *manager, t_philo *philos);

/*utils*/
size_t	get_time(void);
long	ft_atoi(char *nbr);
void	ft_putstr_fd(int fd, char *s);
int		is_number(char *str);
int		ft_usleep(size_t milliseconds);

/*init*/
int		init_structures(t_manager *manager, t_philo *philo, int ac, char **av);

/*threads*/
int		create_threads(t_manager *manager, t_philo *philos);

/*checks*/
int		no_philos_dead(t_philo *philos);
int		check_death(t_philo *philos);
int		check_full(t_philo *philos);

/*routine*/
void	print_msg(t_philo *philos, char *msg);
void	*philos_routine(void *ptr);

void	print_structures(t_manager *manager, t_philo *philos);
#endif 