/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/04 04:38:02 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		is_dead(t_philo *philo);
long	diff_time_ms(struct timeval *time, pthread_mutex_t *lock);
void	safe_inc(int *to_inc, pthread_mutex_t *lock);
int		safe_read(int *to_read, pthread_mutex_t *lock);
void	safe_update_time(struct timeval *time, pthread_mutex_t *lock);

///////////////////////////////////////////////////////////////////////////////]
int	is_dead(t_philo *philo)
{
	int	d;
	int	one_d;

	d = safe_read(&philo->dead, &philo->dead_m);
	one_d = safe_read(&philo->data->someone_dead, &philo->data->someone_dead_m);
	if (d || (philo->data->max_meal < 0 && one_d))
	{
		if (philo->in_hand & 1)
		{
			pthread_mutex_unlock(philo->fork_r);
			philo_speech(philo, "\ttaken from the TABLE,", 'r');
		}
		if ((philo->in_hand >> 1) & 1)
		{
			pthread_mutex_unlock(philo->fork_l);
			philo_speech(philo, "\ttaken from the TABLE,", 'l');
		}
		philo->in_hand = 0;
		return (1);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
// safe return time from last meal
long	diff_time_ms(struct timeval *time, pthread_mutex_t *lock)
{
	struct timeval	time_now;
	long			diff_us;
	long			diff_ms;

	gettimeofday(&time_now, NULL);
	if (lock)
		pthread_mutex_lock(lock);
	diff_us = (time_now.tv_sec - (*time).tv_sec) * 1000000L
		+ (time_now.tv_usec - (*time).tv_usec);
	if (lock)
		pthread_mutex_unlock(lock);
	diff_ms = diff_us / 1000;
	return (diff_ms);
}

///////////////////////////////////////////////////////////////////////////////]
// safe increment
void	safe_inc(int *to_inc, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	(*to_inc)++;
	pthread_mutex_unlock(lock);
}

///////////////////////////////////////////////////////////////////////////////]
// safe read int
int	safe_read(int *to_read, pthread_mutex_t *lock)
{
	int	rtrn;

	pthread_mutex_lock(lock);
	rtrn = *to_read;
	pthread_mutex_unlock(lock);
	return (rtrn);
}

///////////////////////////////////////////////////////////////////////////////]
// safe update philo time
void	safe_update_time(struct timeval *time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	gettimeofday(time, NULL);
	pthread_mutex_unlock(lock);
}
