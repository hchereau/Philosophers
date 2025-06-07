/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:17 by linux             #+#    #+#             */
/*   Updated: 2025/06/07 18:25:22 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (1)
	{
		// Penser
		// Prendre les deux fourchettes (mutex_lock)
		// Manger (usleep time_to_eat)
		// Remettre les fourchettes (mutex_unlock)
		// Dormir (usleep time_to_sleep)
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
		if (pthread_create(&(*philos)[i].thread, NULL, philosopher_routine, &(*philos)[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread %d.\n", i + 1);
			return (FAILED_VALUE);
		}
		i++;
	}
	return (SUCCESS);
}
