/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:57:21 by linux             #+#    #+#             */
/*   Updated: 2025/02/25 00:00:13 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	get_args(int argc, char **argv, t_data *data)
{
	if (argc != 5)
	{
		printf("Error: Wrong number of arguments\n");
		exit(FAILURE);
	}
	data->philo_count = ft_atoi(argv[0]);
	data->time_to_die = ft_atoi(argv[1]);
	data->time_to_eat = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	data->meal_count = ft_atoi(argv[4]);
}
