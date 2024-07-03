/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:23:10 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/03 17:59:39 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo(void *arg);
void	*ft_thread_starve(void *arg);
int		is_dead(t_philo *philo);
void	philo_speech(t_philo *philo, char *state, char rl);

///////////////////////////////////////////////////////////////////////////////]
// THREAD FUNCTION FOR 1 PHILO
void	*ft_philo(void *arg)
{
	pthread_t	thread_starve;
	t_philo		*p;

	p = (t_philo *)arg;
	if (!(p->i % 2))
		usleep(1000);
	if (pthread_create(&thread_starve, NULL, &ft_thread_starve, arg))
		return (put("Error creating thread for philosopher %d\n"), NULL);
	while (!is_dead(p) && p->time_eaten != p->data->max_meal)
	{
		if (p->doing == THINKING && diff_time_ms(p->time) > p->data->tt_think)
			p->doing = AVAILABLE;
		ft_eat(p);
		ft_sleep(p);
		if (p->time_eaten == p->data->max_meal)
			break ;
		ft_think(p);
	}
	pthread_join(thread_starve, NULL);
	if (!is_dead(p) && p->data->max_meal >= 0)
		philo_speech(p, C_530"\t\twent to HEAVEN with a full belly.", 0);
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
// PET THREAD FOR EACH PHILO, check if dead
void	*ft_thread_starve(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_dead(philo) && philo->time_eaten != philo->data->max_meal)
	{
		if (diff_time_ms(philo->time) > philo->data->tt_die)
		{
			philo->dead = 1;
			if (philo->data->max_meal < 0)
			{
				pthread_mutex_lock(&philo->data->someone_dead_m);
				philo->data->someone_dead++;
				pthread_mutex_unlock(&philo->data->someone_dead_m);
			}
			philo_speech(philo, RED"\t\tDIED of hunger, you monster.", 0);
		}
		usleep(1000);
	}
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
int	is_dead(t_philo *philo)
{
	if (philo->dead || philo->data->someone_dead)
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
void	philo_speech(t_philo *philo, char *state, char rl)
{
	long	time_diff;
	char	*hand;
	int		fork;

	time_diff = diff_time_ms(philo->data->time_start);
	if (rl == 'r')
	{
		hand = "right";
		fork = (unsigned long)philo->fork_r % 256;
		printf(C_231"%.3ld ms)\t"RESET C_401" \033[0;3%im(%i) "RESET C_123"%s "
			"his %s fork "C_025"nᵒ%d\n"RESET,
			time_diff, philo->i, philo->i, state, hand, fork);
	}
	else if (rl == 'l')
	{
		hand = "left";
		fork = (unsigned long)philo->fork_l % 256;
		printf(C_231"%.3ld ms)\t"RESET C_401" \033[0;3%im(%i) "RESET C_123"%s "
			"his %s fork "C_025"nᵒ%d\n"RESET,
			time_diff, philo->i, philo->i, state, hand, fork);
	}
	else
		printf(C_231"%.3ld ms)\t"RESET C_401" \033[0;3%im(%i) "RESET"%s\n"
			RESET, time_diff, philo->i, philo->i, state);
}
