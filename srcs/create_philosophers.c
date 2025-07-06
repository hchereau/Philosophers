/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:17 by linux             #+#    #+#             */
/*   Updated: 2025/07/06 15:31:19 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (philosopher->data->num_philosophers == 1)
	{
		pthread_mutex_lock(philosopher->left_forks);
		print_status(philosopher, FORKS_TAKEN);
		usleep(philosopher->data->time_to_die * US_PER_MS);
		pthread_mutex_unlock(philosopher->left_forks);
		return (NULL);
	}
	if (philosopher->id % 2 == 1)
		usleep(philosopher->data->time_to_eat * US_PER_MS);
	while (is_simulation_running(philosopher->data) == SIMULATION_RUNNING)
	{
		philosopher_think(philosopher);
		try_take_forks(philosopher);
		philosopher_eat(philosopher);
		return_forks(philosopher);
	}
	return (NULL);
}

static void	setup_philosopher(t_philosopher *philo, t_data *data, int index)
{
	philo->id = index + 1;
	philo->state = THINKING;
	philo->meals_eaten = 0;
	philo->left_forks = &data->forks[index];
	philo->right_forks = &data->forks[(index + 1) % data->num_philosophers];
	philo->data = data;
	philo->last_meal_time = data->start_time;
}

static void	join_created_threads(t_philosopher *philos, int count)
{
	while (--count >= 0)
		pthread_join(philos[count].thread, NULL);
}

static t_state_data	launch_thread(t_philosopher *philo,
		t_data *data, int id)
{
	if (pthread_create(&philo->thread, NULL, philosopher_routine,
			philo) != 0)
	{
		printf("Error: Failed to create philosopher thread %d.\n",
			id + 1);
		pthread_mutex_lock(&data->simulation_mutex);
		data->simulation_running = SIMULATION_STOPPED;
		pthread_mutex_unlock(&data->simulation_mutex);
		return (FAILED_VALUE);
	}
	return (SUCCESS_VALUE);
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
		setup_philosopher(&(*philos)[i], data, i);
		if (launch_thread(&(*philos)[i], data, i) != SUCCESS_VALUE)
		{
			join_created_threads(*philos, i);
			free(*philos);
			*philos = NULL;
			return (FAILED_VALUE);
		}
		i++;
	}
	return (SUCCESS_VALUE);
}
