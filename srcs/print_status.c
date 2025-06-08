/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 23:47:58 by linux             #+#    #+#             */
/*   Updated: 2025/06/08 00:09:14 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philosopher *philosopher, t_philosopher_state state)
{
	const char	*state_str;
	long		timestamp;

	if (state == THINKING)
		state_str = "is thinking";
	else if (state == EATING)
		state_str = "is eating";
	else if (state == SLEEPING)
		state_str = "is sleeping";
	else if (state == DEAD)
		state_str = "died";
	else
		return ;
	timestamp = get_timestamp() - philosopher->data->start_time;
	pthread_mutex_lock(&philosopher->data->print_mutex);
	printf("%ld %d %s\n", timestamp, philosopher->id, state_str);
	pthread_mutex_unlock(&philosopher->data->print_mutex);
}
