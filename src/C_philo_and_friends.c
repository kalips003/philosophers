/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_philo_and_friends.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:23:10 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/06 23:52:29 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_watcher(void *arg);
void	philo_speech(t_philo *philo, char *state, char rl);

#define MSGDIED "\033[0;31m\t\tDIED of hunger, you monster."
///////////////////////////////////////////////////////////////////////////////]
void	*ft_watcher(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (!safe_read(&data->end, &data->end_m))
	{
		i = (i + 1) % data->num_philo;
		if (diff_time_ms(&data->philos[i].time, &data->philos[i].time_m)
			> data->tt_die && !safe_read(&data->philos[i].dead,
				&data->philos[i].dead_m))
		{
			philo_speech(&data->philos[i], MSGDIED, 0);
			safe_inc(&data->philos[i].dead, &data->philos[i].dead_m);
			safe_inc(&data->someone_dead, &data->someone_dead_m);
			if (data->max_meal < 0 || safe_read(&data->someone_dead,
					&data->someone_dead_m) == data->num_philo)
				break ;
		}
		usleep(1);
	}
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////]
void	philo_speech(t_philo *philo, char *state, char rl)
{
	long	time_diff;
	char	*hand;
	int		fork;

	time_diff = diff_time_ms(&philo->data->time_start, NULL);
	if (rl == 'r')
	{
		hand = "right";
		fork = (unsigned long)philo->fork_r % 256;
	}
	else if (rl == 'l')
	{
		hand = "left";
		fork = (unsigned long)philo->fork_l % 256;
	}
	pthread_mutex_lock(&philo->data->someone_talk_m);
	if (rl == 'r' || rl == 'l')
		printf(C_231"%.4ld ms)\t"RESET C_401" \033[38;5;%im(%i) "RESET
			C_123"%s his %s fork "C_025"nᵒ%d\n"RESET,
			time_diff, philo->i % 256, philo->i, state, hand, fork);
	else
		printf(C_231"%.4ld ms)\t"RESET C_401" \033[38;5;%im(%i) "RESET"%s\n"
			RESET, time_diff, philo->i % 256, philo->i, state);
	pthread_mutex_unlock(&philo->data->someone_talk_m);
}
