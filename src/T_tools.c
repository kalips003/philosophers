/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:21:51 by kalipso           #+#    #+#             */
/*   Updated: 2024/07/03 15:29:54 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	diff_time_ms(struct timeval time);

///////////////////////////////////////////////////////////////////////////////]
long	diff_time_ms(struct timeval time)
{
	struct timeval	time_now;
	long			diff_us;
	long			diff_ms;

	gettimeofday(&time_now, NULL);
	diff_us = (time_now.tv_sec - time.tv_sec) * 1000000L
		+ (time_now.tv_usec - time.tv_usec);
	diff_ms = diff_us / 1000;
	return (diff_ms);
}
