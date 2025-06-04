/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:08:16 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 15:58:10 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

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
		printf("too many philosophers, max is %d\n", MAX_PHILOSOPHERS);
		return (FAILED_VALUE);
	}
	if (data->num_philosophers <= 0 || data->time_to_eat <= 0 ||
	    data->time_to_sleep <= 0 || (argc == 6 && data->max_meals <= 0))
	{
		printf("Invalid argument values.\n");
		return (FAILED_VALUE);
	}
	return (SUCCESS);
}
