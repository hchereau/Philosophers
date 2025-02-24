/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:00:22 by linux             #+#    #+#             */
/*   Updated: 2025/02/25 00:00:34 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_state_functions	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->mutex, NULL) != 0)
	{
		printf("Error: Mutex initialization failed\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
