/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simulation_running.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:53:26 by linux             #+#    #+#             */
/*   Updated: 2025/07/05 14:17:44 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_simulation_state	is_simulation_running(t_data *data)
{
	t_simulation_state	state;

	pthread_mutex_lock(&data->simulation_mutex);
	state = data->simulation_running;
	pthread_mutex_unlock(&data->simulation_mutex);
	return (state);
}
