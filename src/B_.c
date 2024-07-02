/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:02:23 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/02 16:43:18 by kalipso          ###   ########.fr       */
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
	while (!is_dead(philo) && philo->time_eaten != philo->data->num_time_each_philosopher_must_eat)
	{
		if (get_time_diff_in_milli(philo->time) > philo->data->time_to_die)
		{
			philo->dead = 1;
			if (philo->data->num_time_each_philosopher_must_eat < 0)
			{
				pthread_mutex_lock(&philo->data->someone_dead_m);
				philo->data->someone_dead++;
				pthread_mutex_unlock(&philo->data->someone_dead_m);
			}
			printf("%ld ms) [%i] died !!!!!\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
			// pthread_detach(philo->thread_id);
			// break ;
		}
		usleep(1000);
	}
	printf("%d) secondary thread over\n", philo->philo_i);
	return (NULL);
}

int	is_dead(t_philo *philo);
int	is_dead(t_philo *philo)
{
	if (philo->dead || philo->data->someone_dead)
	{
		if (philo->in_hand & 1)
		{
			pthread_mutex_unlock(philo->fork_r);
			printf("%ld ms) [%i] put back his right forks BY FORCE\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
		}
		if ((philo->in_hand >> 1) & 1)
		{
			pthread_mutex_unlock(philo->fork_l);
			printf("%ld ms) [%i] put back his left forks BY FORCE\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
		}
		philo->in_hand = 0;
		return (1);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
void	*ft_philo(void *arg)
{
	pthread_t	thread_starve;

	t_philo *philo = (t_philo*)arg;
	if (pthread_create(&thread_starve, NULL, &ft_thread_starve, arg))
		return (put("Error creating thread for philosopher %d\n"), NULL);
	while (!is_dead(philo) && philo->time_eaten != philo->data->num_time_each_philosopher_must_eat)
	{
		if (!is_dead(philo) && philo->doing == THINKING && get_time_diff_in_milli(philo->time) > philo->data->time_to_think)
			philo->doing = AVAILABLE;
		if (!is_dead(philo) && philo->doing == AVAILABLE)
			ft_eat(philo);
		if (!is_dead(philo) && philo->doing == EATING && get_time_diff_in_milli(philo->time) > philo->data->time_to_eat)
			ft_sleep(philo);
		if (philo->time_eaten == philo->data->num_time_each_philosopher_must_eat)
			break ;
		if (!is_dead(philo) && philo->doing == SLEEPING && get_time_diff_in_milli(philo->time) > philo->data->time_to_sleep)
			ft_think(philo);
	}
	pthread_join(thread_starve, NULL);
	if (!is_dead(philo) && philo->data->num_time_each_philosopher_must_eat >= 0)	
		printf("%ld ms) =====> %i went to heaven with a full belly\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	printf("%ld) -----------------------------------------> %i ended\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
void	ft_eat(t_philo *philo)
{
	if (philo->philo_i % 2)
	{
		printf("%ld ms) [%i] \twaiting for his right fork\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
		pthread_mutex_lock(philo->fork_r);
		philo->in_hand |= 0b01;
		if (is_dead(philo))
			return ;
		printf("%ld ms) [%i] has taken his right fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r);
		if (philo->data->num_philo == 1)
			return ;
		printf("%ld ms) [%i] \twaiting for his left fork\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
		pthread_mutex_lock(philo->fork_l);
		philo->in_hand |= 0b10;
		if (is_dead(philo))
			return ;
		printf("%ld ms) [%i] has taken his left fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_l);
	}
	else
	{
		printf("%ld ms) [%i] \twaiting for his left fork\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
		pthread_mutex_lock(philo->fork_l);
		philo->in_hand |= 0b10;
		if (is_dead(philo))
			return ;
		printf("%ld ms) [%i] has taken his left fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_l);
		printf("%ld ms) [%i] \twaiting for his right fork\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
		pthread_mutex_lock(philo->fork_r);
		philo->in_hand |= 0b01;
		if (is_dead(philo))
			return ;
		printf("%ld ms) [%i] has taken his right fork (%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r);
	}
	printf("%ld ms) - [%i] is eating\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i);
	philo->doing = EATING;
	gettimeofday(&philo->time, NULL);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->in_hand & 1)
	{
		pthread_mutex_unlock(philo->fork_r);
		printf("%ld ms) [%i] put back his right forks (%p)(%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r, philo->fork_l);
	}
	if ((philo->in_hand >> 1) & 1)
	{
		pthread_mutex_unlock(philo->fork_l);
		printf("%ld ms) [%i] put back his left forks (%p)(%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r, philo->fork_l);
	}
	philo->in_hand = 0;
	if (is_dead(philo))
		return ;
	printf("%ld ms) [%i] put back his forks (%p)(%p)\n", get_time_diff_in_milli(philo->data->time_start), philo->philo_i, philo->fork_r, philo->fork_l);
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