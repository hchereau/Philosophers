/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 23:47:58 by linux             #+#    #+#             */
/*   Updated: 2025/07/05 17:57:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

bool	choose_print(t_philosopher_state state, char **state_str)
{
	if (state == THINKING)
		*state_str = "is thinking";
	else if (state == EATING)
		*state_str = "is eating";
	else if (state == SLEEPING)
		*state_str = "is sleeping";
	else if (state == DEAD)
		*state_str = "died";
	else if (state == FORKS_TAKEN)
		*state_str = "has taken a fork";
	else
		return (false);
	return (true);
}

void	print_status(t_philosopher *philosopher, t_philosopher_state state)
{
	char	*state_str;
	long	timestamp;

	if (state != DEAD)
	{
		pthread_mutex_lock(&philosopher->data->simulation_mutex);
		if (philosopher->data->simulation_running == 0)
		{
			pthread_mutex_unlock(&philosopher->data->simulation_mutex);
			return ;
		}
		pthread_mutex_unlock(&philosopher->data->simulation_mutex);
	}
	if (choose_print(state, &state_str) == false)
		return ;
	timestamp = get_timestamp() - philosopher->data->start_time;
	pthread_mutex_lock(&philosopher->data->print_mutex);
	printf("%ld %d %s\n", timestamp, philosopher->id, state_str);
	pthread_mutex_unlock(&philosopher->data->print_mutex);
}
