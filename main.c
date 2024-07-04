/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:53:58 by marvin            #+#    #+#             */
/*   Updated: 2024/07/04 04:14:50 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*******************************************************************************
******************************************************************************/
// <!> - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  </!>
///////////////////////////////////////////////////////////////////////////////]
/*******************************************************************************

			░█████╗░  ███████╗░█████╗░██╗██████╗░███████╗
			██╔══██╗  ██╔════╝██╔══██╗██║██╔══██╗██╔════╝
			███████║  █████╗░░███████║██║██████╔╝█████╗░░
			██╔══██║  ██╔══╝░░██╔══██║██║██╔══██╗██╔══╝░░
			██║░░██║  ██║░░░░░██║░░██║██║██║░░██║███████╗
			╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝╚══════╝

struct timeval {
	time_t	  tv_sec;  // seconds
	suseconds_t tv_usec; // microseconds
};


memset, printf, malloc, free, write,

usleep, gettimeofday,

pthread_create,
pthread_detach, 
pthread_join, 
pthread_mutex_init,
pthread_mutex_destroy, 
pthread_mutex_lock,
pthread_mutex_unlock

	WHY ATTRIBUTES NULL IN:
pthread_create(&t1, NULL);

******************************************************************************/
///////////////////////////////////////////////////////////////////////////////]
int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	ft_ini(ac, av, &data);
	i = -1;
	while (++i < data.num_philo)
	{
		if (pthread_create(&data.philos[i].thread_id, NULL, &ft_philo, &data.philos[i]))
			return (put("Error creating thread for philosopher %d\n"), 1);
	}
	i = -1;
	while (++i < data.num_philo)
		pthread_join(data.philos[i].thread_id, NULL);
	safe_inc(&data.end, &data.end_m);
	pthread_join(data.thread_watcher, NULL);
	end(&data, 0);
	return (0);
}
