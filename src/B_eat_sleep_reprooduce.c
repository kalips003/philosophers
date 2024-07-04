/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_eat_sleep_reprooduce.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:02:23 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/04 04:44:50 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*ft_philo(void *arg);
static int	ft_sleep(t_philo *philo);
static int	ft_eat(t_philo *philo);
static int	ft_eat_0(t_philo *philo);
static int	ft_eat_1(t_philo *philo);

///////////////////////////////////////////////////////////////////////////////]
// THREAD FUNCTION FOR 1 PHILO
void	*ft_philo(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	if (!(p->i % 2))
		usleep(1000);
	while (!is_dead(p))
	{
		if (ft_eat(p))
			break ;
		if (ft_sleep(p))
			break ;
		if (p->doing == SLEEPING && diff_time_ms(&p->time, &p->time_m)
			>= p->data->tt_eat + p->data->tt_sleep)
		{
			philo_speech(p, " == == == is thinking", 0);
			p->doing = THINKING;
		}
		usleep(1);
	}
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
int	ft_eat(t_philo *philo)
{
	if (philo->doing != THINKING)
		return (0);
	if (philo->i % 2)
	{
		if (ft_eat_1(philo))
			return (1);
		if (philo->data->num_philo == 1)
			return (0);
	}
	else
	{
		if (ft_eat_0(philo))
			return (1);
	}
	safe_update_time(&philo->time, &philo->time_m);
	philo_speech(philo, " == is eating", 0);
	philo->doing = EATING;
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
int	ft_sleep(t_philo *philo)
{
	if (philo->doing != EATING || diff_time_ms(&philo->time, &philo->time_m)
		< philo->data->tt_eat)
		return (0);
	pthread_mutex_unlock(philo->fork_r);
	philo_speech(philo, "\tputs back", 'r');
	pthread_mutex_unlock(philo->fork_l);
	philo_speech(philo, "\tputs back", 'l');
	philo->in_hand = 0;
	philo->time_eaten++;
	if (philo->time_eaten == philo->data->max_meal)
	{
		philo_speech(philo, C_530"\t\twent to HEAVEN with a full belly.", 0);
		safe_inc(&philo->dead, &philo->dead_m);
		return (1);
	}
	philo_speech(philo, " == == is sleeping", 0);
	philo->doing = SLEEPING;
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
// void	ft_think(t_philo *p)
// {
// 	if (p->doing != SLEEPING || diff_time_ms(&p->time, &p->time_m)
// 			> p->data->tt_eat + p->data->tt_sleep)
// 		return ;
// 	philo_speech(p, " == == == is thinking", 0);
// 	p->doing = THINKING;
// }

///////////////////////////////////////////////////////////////////////////////]
// for even numbers , start with left hand
static int	ft_eat_0(t_philo *philo)
{
	philo_speech(philo, "\tWAITING for", 'l');
	pthread_mutex_lock(philo->fork_l);
	philo->in_hand |= 0b10;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'l');
	philo_speech(philo, "\tWAITING for", 'r');
	pthread_mutex_lock(philo->fork_r);
	philo->in_hand |= 0b01;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'r');
	return (0);
}

// for odd numbers , start with right hand
static int	ft_eat_1(t_philo *philo)
{
	if (philo->in_hand)
		return (0);
	philo_speech(philo, "\tWAITING for", 'r');
	pthread_mutex_lock(philo->fork_r);
	philo->in_hand |= 0b01;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'r');
	if (philo->data->num_philo == 1)
		return (0);
	philo_speech(philo, "\tWAITING for", 'l');
	pthread_mutex_lock(philo->fork_l);
	philo->in_hand |= 0b10;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'l');
	return (0);
}
