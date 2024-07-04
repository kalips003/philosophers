/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_initialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/04 04:14:50 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_ini(int ac, char **av, t_data *data);
static void	ft_check_args(int ac, char **av, t_data *data);
static void	ft_ini_philo(t_data *data);
static void	h_982(t_data *data, t_philo *philo, int i);

#define MSG_1 "Some of you will die, but its a sacriifice im willing "
///////////////////////////////////////////////////////////////////////////////]
// memset, 
void	ft_ini(int ac, char **av, t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	ft_check_args(ac, av, data);
	if (data->tt_die < data->tt_eat + data->tt_sleep)
		put(ERR"WONT SOMEBODY PLEASE THINK OF THE CHILDREN ?!?\n\n");
	if (data->tt_die <= data->tt_eat * (2 + data->num_philo % 2))
		put(MSG_1"to make!\n\n");
	data->tt_think = data->tt_eat + data->tt_sleep
		+ (data->tt_die - (data->tt_eat + data->tt_sleep)) / 2;
	gettimeofday(&data->time_start, NULL);
	pthread_mutex_init(&data->someone_dead_m, NULL);
	pthread_mutex_init(&data->someone_talk_m, NULL);
	pthread_mutex_init(&data->end_m, NULL);
	ft_ini_philo(data);
	pthread_create(&data->thread_watcher, NULL, &ft_watcher, data);
}

///////////////////////////////////////////////////////////////////////////////]
// just fills and check args
static void	ft_check_args(int ac, char **av, t_data *data)
{
	int	err;

	err = 0;
	if (ac == 5)
		data->max_meal = -1;
	else if (ac == 6)
	{
		data->max_meal = ft_atoi(av[5], &err);
		if (data->max_meal < 0)
			return (put(ERR"negative arg max_meal\n"), exit(0));
	}
	else
		return (put(ERR"bad number of args\n"), exit(0));
	data->num_philo = ft_atoi(av[1], &err);
	data->tt_die = ft_atoi(av[2], &err);
	data->tt_eat = ft_atoi(av[3], &err);
	data->tt_sleep = ft_atoi(av[4], &err);
	if (err)
		return (put(ERR"is that a number?\n"), exit(0));
	if (data->num_philo < 0 || data->tt_die < 0 || data->tt_eat
		< 0 || data->tt_sleep < 0)
		return (put(ERR"negative arg\n"), exit(0));
	if (data->num_philo == 0)
		return (put(ERR"Philosophers are an extinct race\n"), exit(0));
}

///////////////////////////////////////////////////////////////////////////////]
// malloc: philos & forks
static void	ft_ini_philo(t_data *data)
{
	int	i;

	data->philos = (t_philo *)mem(0, sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (put(ERRM"malloc 0\n"), exit(1));
	data->forks = (pthread_mutex_t *)mem(0, sizeof(pthread_mutex_t)
			* data->num_philo);
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
	philo->i = i;
	philo->data = data;
	philo->time = data->time_start;
	pthread_mutex_init(&data->forks[i - 1], NULL);
	pthread_mutex_init(&philo->time_m, NULL);
	pthread_mutex_init(&philo->dead_m, NULL);
}
