/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:17 by linux             #+#    #+#             */
/*   Updated: 2025/07/04 15:27:59 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (philosopher->id % 2 != 0)
		usleep(philosopher->data->time_to_eat * 1000 / 2);
	while (is_simulation_running(philosopher->data))
	{
		philosopher_think(philosopher);
		try_take_forks(philosopher);
		// philosopher->last_meal_time = get_timestamp();
		philosopher_eat(philosopher);
		return_forks(philosopher);
	}
	return (NULL);
}

t_state_data	create_philosophers(t_data *data, t_philosopher **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philosopher) * data->num_philosophers);
	if (*philos == NULL)
	{
		printf("Error: Memory allocation failed for philosophers.\n");
		return (FAILED_VALUE);
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].state = THINKING;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].left_forks = &data->forks[i];
		(*philos)[i].right_forks = &data->forks[(i + 1) % data->num_philosophers];
		(*philos)[i].data = data;
		(*philos)[i].last_meal_time = data->start_time;
		if (pthread_create(&(*philos)[i].thread, NULL, philosopher_routine, &(*philos)[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread %d.\n", i + 1);
			return (FAILED_VALUE);
		}
		i++;
	}
	return (SUCCESS_VALUE);
}
