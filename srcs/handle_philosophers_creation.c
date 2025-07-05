/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosophers_creation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:52:07 by hucherea          #+#    #+#             */
/*   Updated: 2025/07/05 16:55:47 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

static int	check_death(t_philosopher *philos, t_data *data)
{
	int		i;
	long	now;
	long	last_meal_time;

	i = 0;
	while (i < data->num_philosophers)
	{
		now = get_timestamp();
		pthread_mutex_lock(&data->simulation_mutex);
		last_meal_time = philos[i].last_meal_time;
		pthread_mutex_unlock(&data->simulation_mutex);
		if (now - last_meal_time > data->time_to_die)
		{
			print_status(&philos[i], DEAD);
			pthread_mutex_lock(&data->simulation_mutex);
			data->simulation_running = 0;
			pthread_mutex_unlock(&data->simulation_mutex);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_meals(t_philosopher *philos, t_data *data)
{
	int	j;	

	if (data->max_meals == INFINITE_MEALS)
		return (1);
	j = 0;
	while (j < data->num_philosophers)
	{
		pthread_mutex_lock(&data->simulation_mutex);
		if (philos[j].meals_eaten < data->max_meals)
		{
			pthread_mutex_unlock(&data->simulation_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->simulation_mutex);
		j++;
	}
	pthread_mutex_lock(&data->simulation_mutex);
	data->simulation_running = 0;
	pthread_mutex_unlock(&data->simulation_mutex);
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philosopher	*philos;
	t_data			*data;

	philos = (t_philosopher *)arg;
	data = philos[0].data;
	while (is_simulation_running(data))
	{
		if (!check_death(philos, data))
			return (NULL);
		if (!check_meals(philos, data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

t_main_state	handle_philosophers_creation(t_data	*data,
				t_philosopher **philos)
{
	if (create_philosophers(data, philos) != SUCCESS_VALUE)
	{
		printf("Error: Failed to create philosophers.\n");
		cleanup(data, NULL);
		return (FAILURE);
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine,
			*philos) != 0)
	{
		printf("Error: Failed to create monitor thread.\n");
		pthread_mutex_lock(&data->simulation_mutex);
		data->simulation_running = 0;
		pthread_mutex_unlock(&data->simulation_mutex);
		start_simulation(data, *philos);
		cleanup(data, *philos);
		return (FAILURE);
	}
	return (SUCCESS);
}
