/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:05:36 by linux             #+#    #+#             */
/*   Updated: 2025/02/26 23:55:12 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	init_threads(t_data *data, pthread_t *philo_threads)
{
	size_t	i;

	i = 0;
	philo_threads = malloc(sizeof(pthread_t) * data->philo_count);
	if (philo_threads == NULL)
	{
		printf("Error: Malloc failed\n");
		exit(FAILURE);
	}
	while (i < data->philo_count)
	{
		if (pthread_create(&philo_threads[i], NULL, philo_routine, data) != 0)
		{
			printf("Error: Thread creation failed\n");
			exit(FAILURE);
		}
		++i;
	}
}

void	wait_threads(t_data *data, pthread_t *philo_threads)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(philo_threads[i], NULL) != 0)
		{
			printf("Error: Thread join failed\n");
			exit(FAILURE);
		}
		++i;
	}
}

void	core_routine(t_data *data)
{
	pthread_t	*philo_threads;

	init_threads(data, philo_threads);
	wait_threads(data, philo_threads);
}
