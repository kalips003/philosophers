/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:02:23 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/03 16:26:12 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"


int		is_dead(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
static void	f(t_philo *philo, char *state, char rl);

///////////////////////////////////////////////////////////////////////////////]
int	is_dead(t_philo *philo)
{
	if (philo->dead || philo->data->someone_dead)
	{
		if (philo->in_hand & 1)
		{
			pthread_mutex_unlock(philo->fork_r);
			f(philo, "\ttaken from his CORPSE,", 'r');
			// printf("%.4ld ms) [%i] put back his right forks BY FORCE\n", diff_time_ms(philo->data->time_start), philo->i);
		}
		if ((philo->in_hand >> 1) & 1)
		{
			pthread_mutex_unlock(philo->fork_l);
			f(philo, "\ttaken from his CORPSE,", 'l');
			// printf("%.4ld ms) [%i] put back his left forks BY FORCE\n", diff_time_ms(philo->data->time_start), philo->i);
		}
		philo->in_hand = 0;
		return (1);
	}
	return (0);
}

	// "\twaiting for";
	// "\thas taken";
static void	f(t_philo *philo, char *state, char rl)
{
	long	time_diff;
	char	*hand;
	int		fork;

	time_diff = diff_time_ms(philo->data->time_start);
	if (rl == 'r')
	{
		hand = "right";
		fork = (unsigned long)philo->fork_r % 256;
	}
	else
	{
		hand = "left";
		fork = (unsigned long)philo->fork_l % 256;
	}
	printf("%.4ld ms) [%i] %s his %s fork (%d)\n", time_diff, philo->i, state, hand, fork);
}
///////////////////////////////////////////////////////////////////////////////]
void	ft_eat(t_philo *philo)
{
	if (philo->i % 2)
	{
		f(philo, "\twaiting for", 'r');
		// printf("%.4ld ms) [%i] \twaiting for his right fork\n", diff_time_ms(philo->data->time_start), philo->i);
		pthread_mutex_lock(philo->fork_r);
		philo->in_hand |= 0b01;
		if (is_dead(philo))
			return ;
		f(philo, "\thas taken", 'r');
		// printf("%.4ld ms) [%i] has taken his right fork (%p)\n", diff_time_ms(philo->data->time_start), philo->i, philo->fork_r);
		// printf("%.4ld %i has taken a fork\n", diff_time_ms(philo->data->time_start), philo->i);
		if (philo->data->num_philo == 1)
			return ;
		f(philo, "\twaiting for", 'l');
		// printf("%.4ld ms) [%i] \twaiting for his left fork\n", diff_time_ms(philo->data->time_start), philo->i);
		pthread_mutex_lock(philo->fork_l);
		philo->in_hand |= 0b10;
		if (is_dead(philo))
			return ;
		// printf("%.4ld ms) [%i] has taken his left fork (%p)\n", diff_time_ms(philo->data->time_start), philo->i, philo->fork_l);
		f(philo, "\thas taken", 'l');
		// printf("%.4ld %i has taken a fork\n", diff_time_ms(philo->data->time_start), philo->i);
	}
	else
	{
		f(philo, "\twaiting for", 'l');
		// printf("%.4ld ms) [%i] \twaiting for his left fork\n", diff_time_ms(philo->data->time_start), philo->i);
		pthread_mutex_lock(philo->fork_l);
		philo->in_hand |= 0b10;
		if (is_dead(philo))
			return ;
		f(philo, "\thas taken", 'l');
		// printf("%.4ld ms) [%i] has taken his left fork (%p)\n", diff_time_ms(philo->data->time_start), philo->i, philo->fork_l);
		// printf("%.4ld %i has taken a fork\n", diff_time_ms(philo->data->time_start), philo->i);
		f(philo, "\twaiting for", 'r');
		// printf("%.4ld ms) [%i] \twaiting for his right fork\n", diff_time_ms(philo->data->time_start), philo->i);
		pthread_mutex_lock(philo->fork_r);
		philo->in_hand |= 0b01;
		if (is_dead(philo))
			return ;
		f(philo, "\thas taken", 'r');
		// printf("%.4ld ms) [%i] has taken his right fork (%p)\n", diff_time_ms(philo->data->time_start), philo->i, philo->fork_r);
		// printf("%.4ld %i has taken a fork\n", diff_time_ms(philo->data->time_start), philo->i);
	}
	printf("%.4ld ms) == [%i] is eating\n", diff_time_ms(philo->data->time_start), philo->i);
	// printf("%.4ld %i is eating\n", diff_time_ms(philo->data->time_start), philo->i);
	philo->doing = EATING;
	gettimeofday(&philo->time, NULL);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->in_hand & 1)
	{
		pthread_mutex_unlock(philo->fork_r);
		f(philo, "\tputs back", 'r');
		// printf("%.4ld ms) [%i] puts back his right forks (%p)\n", diff_time_ms(philo->data->time_start), philo->i, philo->fork_r);
	}
	if ((philo->in_hand >> 1) & 1)
	{
		pthread_mutex_unlock(philo->fork_l);
		f(philo, "\tputs back", 'l');
		// printf("%.4ld ms) [%i] put back his left forks (%p)\n", diff_time_ms(philo->data->time_start), philo->i, philo->fork_l);
	}
	philo->in_hand = 0;
	if (is_dead(philo))

		return ;
	if (++philo->time_eaten == philo->data->max_meal)
		return ;
	printf("%.4ld ms) == == [%i] is sleeping\n", diff_time_ms(philo->data->time_start), philo->i);
	// printf("%.4ld %i is sleeping\n", diff_time_ms(philo->data->time_start), philo->i);
	philo->doing = SLEEPING;
}

void	ft_think(t_philo *philo)
{
	printf("%.4ld ms) == == == [%i] is thinking\n", diff_time_ms(philo->data->time_start), philo->i);
	// printf("%.4ld %i is thinking\n", diff_time_ms(philo->data->time_start), philo->i);
	philo->doing = THINKING;
}
