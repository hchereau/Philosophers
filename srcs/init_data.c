/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:08:16 by linux             #+#    #+#             */
/*   Updated: 2025/07/06 14:45:54 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

static t_main_state	init_mutexs(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (data->forks == NULL)
	{
		printf("Error: Memory allocation failed for forks.\n");
		return (FAILURE);
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Error: Failed to initialize mutex for fork %d.\n",
				i + 1);
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return (FAILURE);
		}
		++i;
	}
	return (SUCCESS);
}

static t_state_data	parse_args(t_data *data, int argc, char **argv)
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
		printf("Error: too many philosophers, max is %d\n",
			MAX_PHILOSOPHERS);
		return (FAILED_VALUE);
	}
	if (data->num_philosophers <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0
		|| (argc == 6 && data->max_meals <= 0)
		|| data->time_to_die <= 0)
	{
		printf("Error: Invalid argument values.\n");
		return (FAILED_VALUE);
	}
	return (SUCCESS_VALUE);
}

t_state_data	handle_init_mutex(t_data *data)
{
	if (init_mutexs(data) != SUCCESS)
	{
		printf("Error: Failed to initialize mutexes.\n");
		return (FAILED_VALUE);
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		printf("Error: Failed to initialize print mutex.\n");
		return (FAILED_VALUE);
	}
	return (SUCCESS_VALUE);
}

t_state_data	init_data(t_data *data, int argc, char **argv)
{
	int	i;

	if (parse_args(data, argc, argv) != SUCCESS_VALUE)
		return (FAILED_VALUE);
	if (handle_init_mutex(data) == FAILED_VALUE)
		return (FAILED_VALUE);
	if (pthread_mutex_init(&data->simulation_mutex, NULL) != 0)
	{
		printf("Error: Failed to initialize simulation mutex.\n");
		i = 0;
		while (i < data->num_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
		pthread_mutex_destroy(&data->print_mutex);
		return (FAILED_VALUE);
	}
	data->simulation_running = SIMULATION_RUNNING;
	return (SUCCESS_VALUE);
}
