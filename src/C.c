/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:23:10 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/03 16:10:40 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo(void *arg);
void	*ft_thread_starve(void *arg);

///////////////////////////////////////////////////////////////////////////////]
void	*ft_philo(void *arg)
{
	pthread_t	thread_starve;

	t_philo *philo = (t_philo*)arg;
	if (!(philo->i % 2))
		usleep(1000);
	if (pthread_create(&thread_starve, NULL, &ft_thread_starve, arg))
		return (put("Error creating thread for philosopher %d\n"), NULL);
	while (!is_dead(philo) && philo->time_eaten != philo->data->max_meal)
	{
		if (!is_dead(philo) && philo->doing == THINKING && diff_time_ms(philo->time) > philo->data->time_to_think)
			philo->doing = AVAILABLE;
		if (!is_dead(philo) && philo->doing == AVAILABLE)
			ft_eat(philo);
		if (!is_dead(philo) && philo->doing == EATING && diff_time_ms(philo->time) > philo->data->time_to_eat)
			ft_sleep(philo);
		if (philo->time_eaten == philo->data->max_meal)
			break ;
		if (!is_dead(philo) && philo->doing == SLEEPING && diff_time_ms(philo->time) > philo->data->time_to_eat + philo->data->time_to_sleep)
			ft_think(philo);
	}
	pthread_join(thread_starve, NULL);
	// if (!is_dead(philo) && philo->data->max_meal >= 0)
		// printf("%ld ms) =====> %i went to heaven with a full belly\n", diff_time_ms(philo->data->time_start), philo->i);
	// printf("%ld) -----------------------------------------> %i ended\n", diff_time_ms(philo->data->time_start), philo->i);
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
void	*ft_thread_starve(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while (!is_dead(philo) && philo->time_eaten != philo->data->max_meal)
	{
		if (diff_time_ms(philo->time) > philo->data->time_to_die)
		{
			philo->dead = 1;
			if (philo->data->max_meal < 0)
			{
				pthread_mutex_lock(&philo->data->someone_dead_m);
				philo->data->someone_dead++;
				pthread_mutex_unlock(&philo->data->someone_dead_m);
			}
			// printf("%ld ms) [%i] died !!!!!\n", diff_time_ms(philo->data->time_start), philo->i);
			printf("%ld %i died\n", diff_time_ms(philo->data->time_start), philo->i);
			// pthread_detach(philo->thread_id);
			// break ;
		}
		usleep(1000);
	}
	// printf("%d) secondary thread over\n", philo->i);
	return (NULL);
}