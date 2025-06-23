/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 23:46:10 by linux             #+#    #+#             */
/*   Updated: 2025/06/23 22:45:50 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	philosopher_think(t_philosopher *philosopher)
{
	print_status(philosopher, THINKING);
}

void	try_take_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(philosopher->left_forks);
		print_status(philosopher, FORKS_TAKEN);
		pthread_mutex_lock(philosopher->right_forks);
		print_status(philosopher, FORKS_TAKEN);
	}
	else
	{
		pthread_mutex_lock(philosopher->right_forks);
		print_status(philosopher, FORKS_TAKEN);
		pthread_mutex_lock(philosopher->left_forks);
		print_status(philosopher, FORKS_TAKEN);
	}
}

void	philosopher_eat(t_philosopher *philosopher)
{
	print_status(philosopher, EATING);
	usleep(philosopher->data->time_to_eat * 1000);
	philosopher->meals_eaten++;
	pthread_mutex_lock(&philosopher->data->simulation_mutex);
	philosopher->last_meal_time = get_timestamp();
	pthread_mutex_unlock(&philosopher->data->simulation_mutex);
}

void	return_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->left_forks);
	pthread_mutex_unlock(philosopher->right_forks);
	print_status(philosopher, SLEEPING);
	usleep(philosopher->data->time_to_sleep * 1000);
}
