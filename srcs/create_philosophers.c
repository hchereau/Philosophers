/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:17 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 16:21:30 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

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
		if (pthread_create(&(*philos)[i].thread, NULL, philosopher_routine, &(*philos)[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread %d.\n", i + 1);
			return (FAILED_VALUE);
		}
		i++;
	}
	return (SUCCESS);
}
