/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:20 by linux             #+#    #+#             */
/*   Updated: 2025/06/08 00:10:15 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

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
		return (FAILURE);
	}
	if (init_data(&data, argc, argv) != SUCCESS)
	{
		return (FAILURE);
	}
	data.start_time = get_timestamp();
	if (create_philosophers(&data, &philos) != 0)
	{
		printf("Error: Failed to create philosophers.\n");
		return (FAILURE);
	}
	start_simulation(&data, philos);
	cleanup(&data);
	return (SUCCESS);
}
