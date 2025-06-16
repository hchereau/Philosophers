/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:08:16 by linux             #+#    #+#             */
/*   Updated: 2025/06/08 23:36:02 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

static t_main_state	init_mutexs(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (data->forks == NULL)
	{
		printf("Error: Memory allocation failed for forks.\n");
		exit(FAILURE);
	}
	for (int i = 0; i < data->num_philosophers; i++)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Error: Failed to initialize mutex for fork %d.\n", i + 1);
			exit(FAILURE);
		}
	}
	return (SUCCESS);
}

t_state_data	init_data(t_data *data, int argc, char **argv)
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = INFINITE_MEALS;
	if (data->num_philosophers > MAX_PHILOSOPHERS)
	{
		printf("Error: too many philosophers, max is %d\n", MAX_PHILOSOPHERS);
		return (FAILED_VALUE);
	}
	if (data->num_philosophers <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || (argc == 6 && data->max_meals <= 0))
	{
		printf("Error: Invalid argument values.\n");
		return (FAILED_VALUE);
	}
	if (init_mutexs(data) != SUCCESS)
	{
		printf("Error: Failed to initialize mutexes.\n");
		return (FAILED_VALUE);
	}
	pthread_mutex_init(&data->simulation_mutex, NULL);
	data->simulation_running = 1;
	return (SUCCESS_VALUE);
}
