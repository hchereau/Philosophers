/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:51:25 by linux             #+#    #+#             */
/*   Updated: 2025/07/05 18:01:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	cleanup(t_data *data, t_philosopher *philos)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i]);
			++i;
		}
		free(data->forks);
		data->forks = NULL;
	}
	if (philos != NULL)
		free(philos);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->simulation_mutex);
}
