/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:02:23 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/02 14:50:43 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

void	*ft_thread_starve(void *arg);
void	*ft_philo(void *arg);

void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
///////////////////////////////////////////////////////////////////////////////]
void	*ft_thread_starve(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while (philo->time_eaten != philo->data->num_time_each_philosopher_must_eat)
	{
		if (get_time_diff_in_milli(philo->time) > philo->data->time_to_die)
		{
			philo->dead = 1;
			printf("%ld ms) [%i] died !!!!!\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
void	*ft_philo(void *arg)
{
	pthread_t	thread_starve;

	t_philo *philo = (t_philo*)arg;
	if (pthread_create(&thread_starve, NULL, &ft_thread_starve, arg))
		return (put("Error creating thread for philosopher %d\n"), NULL);
	while (!philo->dead && philo->time_eaten < philo->data->num_time_each_philosopher_must_eat)
	{
		
		if (!philo->dead && philo->doing == THINKING && get_time_diff_in_milli(philo->time) > philo->data->time_to_think)
			philo->doing = AVAILABLE;
		if (!philo->dead && philo->doing == AVAILABLE)
			ft_eat(philo);
		if (!philo->dead && philo->doing == EATING && get_time_diff_in_milli(philo->time) > philo->data->time_to_eat)
			ft_sleep(philo);
		if (!philo->dead && philo->doing == SLEEPING && get_time_diff_in_milli(philo->time) > philo->data->time_to_sleep)
			ft_think(philo);
	}
	pthread_join(thread_starve, NULL);
	if (!philo->dead)	
		printf("%ld ms) =====> %i went to heaven with a full belly\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
void	ft_eat(t_philo *philo)
{
	if (philo->philo_i % 2)
	{
		pthread_mutex_lock(philo->fork_r);
		printf("%ld ms) [%i] has taken his right fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r);
		pthread_mutex_lock(philo->fork_l);
		printf("%ld ms) [%i] has taken his left fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_l);
	}
	else
	{
		pthread_mutex_lock(philo->fork_l);
		printf("%ld ms) [%i] has taken his left fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_l);
		pthread_mutex_lock(philo->fork_r);
		printf("%ld ms) [%i] has taken his right fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r);
	}
	printf("%ld ms) - [%i] is eating\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	philo->doing = EATING;
	gettimeofday(&philo->time, NULL);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
	philo->in_hand = 0;
	if (++philo->time_eaten == philo->data->num_time_each_philosopher_must_eat)
		return ;
	printf("%ld ms) - - [%i] is sleeping\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	philo->doing = SLEEPING;
}

void	ft_think(t_philo *philo)
{
	printf("%ld ms) - - - [%i] is thinking\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	philo->doing = THINKING;
}