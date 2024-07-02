/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/02 09:11:16 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end(t_data *data, int exit_code);
///////////////////////////////////////////////////////////////////////////////]
void	end(t_data *data, int exit_code)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i]);
	// pthread_detach(thread_id);
	free_s(data->philos);
	free_s(data->forks);
	exit(exit_code);
}