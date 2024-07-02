/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_initialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/02 16:05:10 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		ft_check_args(int ac, char **av, t_data *data);
void		ft_ini_philo(t_data *data);
static void	h_982(t_data *data, t_philo *philo, int i);
///////////////////////////////////////////////////////////////////////////////]
void	ft_check_args(int ac, char **av, t_data *data)
{
	int	err[5];

	ft_memset(&err, 0, sizeof(int) * 5);
	if (ac == 5)
		data->num_time_each_philosopher_must_eat = -1;
	else if (ac == 6)
	{
		data->num_time_each_philosopher_must_eat = ft_atoi(av[5], &err[0]);
		if (data->num_time_each_philosopher_must_eat < 0)
			return (put(ERR"negative arg\n"), exit(0));
	}
	else
		return (put(ERR"bad number of args\n"), exit(0));
	data->num_philo = ft_atoi(av[1], &err[1]);
	data->time_to_die = ft_atoi(av[2], &err[2]);
	data->time_to_eat = ft_atoi(av[3], &err[3]);
	data->time_to_sleep = ft_atoi(av[4], &err[4]);
	if (err[0] || err[1] || err[2] || err[3] || err[4])
		return (put(ERR"is that a number?\n"), exit(0));
	if (data->num_philo < 1 || data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (put(ERR"negative arg\n"), exit(0));
	if (data->time_to_die < data->time_to_eat + data->time_to_sleep)
		put(ERR"WONT SOMEBODY PLEASE THINK OF THE CHILDREN ?!?\n");
	data->time_to_think = data->time_to_die - (data->time_to_eat + data->time_to_sleep - 1);
	gettimeofday(&data->time_start, NULL);
	pthread_mutex_init(&data->someone_dead_m, NULL);
}

///////////////////////////////////////////////////////////////////////////////]
void	ft_ini_philo(t_data *data)
{
	int		i;

	data->philos = (t_philo	*)mem(0, sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (put(ERRM"malloc 0\n"), exit(1));
	data->forks = (pthread_mutex_t *)mem(0, sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (put(ERRM"malloc 1\n"), free_s(data->philos), exit(1));
	i = -1;
	while (++i < data->num_philo)
		h_982(data, &data->philos[i], i + 1);
}

// i = [1, num_philo]
static void	h_982(t_data *data, t_philo *philo, int i)
{
	if (i == 1)
	{
		// if (data->num_philo == 1)
		philo->fork_r = &data->forks[0];
		philo->fork_l = &data->forks[1];
	}
	else if (i == data->num_philo)
	{
		philo->fork_r = &data->forks[data->num_philo - 1];
		philo->fork_l = &data->forks[0];
	}
	else
	{
		philo->fork_r = &data->forks[i - 1];
		philo->fork_l = &data->forks[i];
	}
	philo->philo_i = i;
	philo->data = data;
	philo->time = data->time_start;
	pthread_mutex_init(&data->forks[i - 1], NULL);
}