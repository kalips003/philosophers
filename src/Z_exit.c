/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Z_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/04 04:14:50 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(t_data *data, int exit_code);

///////////////////////////////////////////////////////////////////////////////]
void	end(t_data *data, int exit_code)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].dead_m);
		pthread_mutex_destroy(&data->philos[i].time_m);
	}
	pthread_mutex_destroy(&data->end_m);
	pthread_mutex_destroy(&data->someone_dead_m);
	pthread_mutex_destroy(&data->someone_talk_m);
	free_s(data->philos);
	free_s(data->forks);
	exit(exit_code);
}
