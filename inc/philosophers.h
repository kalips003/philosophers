/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:55:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/02 14:25:13 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "pthread.h"

# include "libft.h"

# define ERR "\033[0;31mError - \e[0m"
# define ERRM "\033[0;32mError - \e[0m"

# define AVAILABLE 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD -1

#ifndef _USECONDS_T
typedef unsigned int useconds_t;
#endif

///////////////////////////////////////////////////////////////////////////////]
//
//			▒█▀▄▀█ ░█▀▀█ ▒█▄░▒█ ▒█▀▀▄ ░█▀▀█ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀█ ▒█░░▒█
//			▒█▒█▒█ ▒█▄▄█ ▒█▒█▒█ ▒█░▒█ ▒█▄▄█ ░▒█░░ ▒█░░▒█ ▒█▄▄▀ ▒█▄▄▄█
//			▒█░░▒█ ▒█░▒█ ▒█░░▀█ ▒█▄▄▀ ▒█░▒█ ░▒█░░ ▒█▄▄▄█ ▒█░▒█ ░░▒█░░
//useconds_t
///////////////////////////////////////////////////////////////////////////////]
// num_philo . time_to_die . time_to_eat . time_to_sleep . [num_time_each_philosopher_must_eat]

// struct timeval {
// 	time_t	  tv_sec;  // seconds
// 	suseconds_t tv_usec; // microseconds
// };

typedef struct s_philo	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;

	struct timeval	time_start;

	int			num_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_time_each_philosopher_must_eat;

	int			time_to_think;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_i;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	struct timeval	time;
	t_data			*data;
	int				doing;
	int				in_hand;
	int				time_eaten;
	int				dead;
}	t_philo;

///////////////////////////////////////////////////////////////////////////////]
/********************************
		A
********************************/
void	ft_check_args(int ac, char **av, t_data *data);
void	ft_ini_philo(t_data *data);




/********************************
		B
********************************/
void	*ft_thread_starve(void *arg);
void	*ft_philo(void *arg);

void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);




/********************************
		Z
********************************/
long	get_time_diff_in_milli(struct timeval time);

void	end(t_data *data, int exit_code);

#endif
