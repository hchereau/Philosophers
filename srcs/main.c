/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:20 by linux             #+#    #+#             */
/*   Updated: 2025/06/23 22:27:26 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philosopher	*philos;
	t_data			*data;
	int				i;
	long			now;

	philos = (t_philosopher *)arg;
	data = philos[0].data;
	while (SIMULATION_RUNNING)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			now = get_timestamp();
			if (now - philos[i].last_meal_time > data->time_to_die)
			{
				print_status(&philos[i], DEAD);
				pthread_mutex_lock(&data->simulation_mutex);
				data->simulation_running = 0;
				pthread_mutex_unlock(&data->simulation_mutex);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
}

static void	start_simulation(t_data *data, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_data			data;
	t_philosopher	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s num_philosophers time_to_die time_to_eat time_to_sleep [max_meals]\n", argv[0]);
		return (FAILURE);
	}
	if (init_data(&data, argc, argv) != SUCCESS)
	{
		return (FAILURE);
	}
	data.start_time = get_timestamp();
	if (create_philosophers(&data, &philos) != SUCCESS)
	{
		printf("Error: Failed to create philosophers.\n");
		return (FAILURE);
	}
	pthread_create(&data.monitor_thread, NULL, monitor_routine, philos);
	start_simulation(&data, philos);
	pthread_join(data.monitor_thread, NULL);
	cleanup(&data, philos);
	return (SUCCESS);
}
