/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:02:23 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/03 17:51:29 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		ft_eat(t_philo *philo);
static int	ft_eat_0(t_philo *philo);
static int	ft_eat_1(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);

///////////////////////////////////////////////////////////////////////////////]
void	ft_eat(t_philo *philo)
{
	if (!(!is_dead(philo) && philo->doing == AVAILABLE))
		return ;
	if (philo->i % 2)
	{
		if (ft_eat_1(philo))
			return ;
	}
	else
	{
		if (ft_eat_0(philo))
			return ;
	}
	philo_speech(philo, " == is eating", 0);
	philo->doing = EATING;
	gettimeofday(&philo->time, NULL);
}

// for even numbers , start with left hand
static int	ft_eat_0(t_philo *philo)
{
	philo_speech(philo, "\twaiting for", 'l');
	pthread_mutex_lock(philo->fork_l);
	philo->in_hand |= 0b10;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'l');
	philo_speech(philo, "\twaiting for", 'r');
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
	philo_speech(philo, "\twaiting for", 'r');
	pthread_mutex_lock(philo->fork_r);
	philo->in_hand |= 0b01;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'r');
	if (philo->data->num_philo == 1)
		return (1);
	philo_speech(philo, "\twaiting for", 'l');
	pthread_mutex_lock(philo->fork_l);
	philo->in_hand |= 0b10;
	if (is_dead(philo))
		return (1);
	philo_speech(philo, C_321"\thas taken", 'l');
	return (0);
}

///////////////////////////////////////////////////////////////////////////////]
void	ft_sleep(t_philo *philo)
{
	if (!(!is_dead(philo) && philo->doing == EATING
			&& diff_time_ms(philo->time) > philo->data->tt_eat))
		return ;
	if (philo->in_hand & 1)
	{
		pthread_mutex_unlock(philo->fork_r);
		philo_speech(philo, "\tputs back", 'r');
	}
	if ((philo->in_hand >> 1) & 1)
	{
		pthread_mutex_unlock(philo->fork_l);
		philo_speech(philo, "\tputs back", 'l');
	}
	philo->in_hand = 0;
	if (++philo->time_eaten == philo->data->max_meal)
		return ;
	philo_speech(philo, " == == is sleeping", 0);
	philo->doing = SLEEPING;
}

///////////////////////////////////////////////////////////////////////////////]
void	ft_think(t_philo *p)
{
	if (!(!is_dead(p) && p->doing == SLEEPING
			&& diff_time_ms(p->time) > p->data->tt_eat + p->data->tt_sleep))
		return ;
	philo_speech(p, " == == == is thinking", 0);
	p->doing = THINKING;
}
