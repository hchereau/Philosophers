/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:08:16 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 15:42:39 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_state_data	init_data(t_data *data, int argc, char **argv)
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_eat = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[4]);
	else
		data->max_meals = -1;
	if (data->num_philosophers <= 0 || data->time_to_eat <= 0 ||
	    data->time_to_sleep <= 0 || (argc == 6 && data->max_meals <= 0))
	{
		return (FAILED_VALUE);
	}
	return (SUCCESS);
}
