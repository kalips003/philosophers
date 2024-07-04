/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:55:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/04 04:35:58 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "pthread.h"

# include "libft.h"

# define THINKING 0
# define EATING 1
# define SLEEPING 2

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
// num_philo . tt_die . tt_eat . tt_sleep . [max_meal]

// struct timeval {
// 	time_t	  tv_sec;  // seconds
// 	suseconds_t tv_usec; // microseconds
// };

typedef struct s_philo	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		thread_watcher;

	struct timeval	time_start;

	int				num_philo;
	int				max_meal;

	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				tt_think;

	int				end;
	int				someone_dead;
	pthread_mutex_t	end_m;
	pthread_mutex_t	someone_dead_m;
	pthread_mutex_t	someone_talk_m;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread_id;
	int				i;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;

	struct timeval	time;
	int				dead;
	pthread_mutex_t	time_m;
	pthread_mutex_t	dead_m;

	int				time_eaten;
	int				in_hand;
	int				doing;
}	t_philo;

///////////////////////////////////////////////////////////////////////////////]
/********************************
		A
********************************/
void	ft_ini(int ac, char **av, t_data *data);

/********************************
		B
********************************/
void	*ft_philo(void *arg);

/********************************
		C
********************************/
void	*ft_watcher(void *arg);
void	philo_speech(t_philo *philo, char *state, char rl);
/********************************
		T
********************************/
int		is_dead(t_philo *philo);
long	diff_time_ms(struct timeval *time, pthread_mutex_t *lock);
void	safe_inc(int *to_inc, pthread_mutex_t *lock);
int		safe_read(int *to_read, pthread_mutex_t *lock);
void	safe_update_time(struct timeval *time, pthread_mutex_t *lock);
/********************************
		Z
********************************/
void	end(t_data *data, int exit_code);

#endif
