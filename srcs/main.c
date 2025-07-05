/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:20 by linux             #+#    #+#             */
/*   Updated: 2025/07/05 16:54:31 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	start_simulation(t_data *data, t_philosopher *philos)
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
		printf("Usage: %s num_philosophers time_to_die time_to_eat"
			" time_to_sleep [max_meals]\n", argv[0]);
		return (FAILURE);
	}
	philos = NULL;
	if (init_data(&data, argc, argv) != SUCCESS_VALUE)
		return (FAILURE);
	data.start_time = get_timestamp();
	if (handle_philosophers_creation(&data, &philos) == FAILURE)
		return (FAILURE);
	start_simulation(&data, philos);
	pthread_join(data.monitor_thread, NULL);
	cleanup(&data, philos);
	return (SUCCESS);
}
