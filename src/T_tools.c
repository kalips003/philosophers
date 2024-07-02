/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/02 09:13:34 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time_diff_in_milli(struct timeval time);
///////////////////////////////////////////////////////////////////////////////]
long	get_time_diff_in_milli(struct timeval time)
{
	struct timeval	time_now;
	long	time_diff_us;
	long	time_diff_ms;

	gettimeofday(&time_now, NULL);
	// Calculate time difference in microseconds
	time_diff_us = (time_now.tv_sec - time.tv_sec) * 1000000L + (time_now.tv_usec - time.tv_usec);
	// Convert microseconds to milliseconds
	time_diff_ms = time_diff_us / 1000;
	return (time_diff_ms);
}