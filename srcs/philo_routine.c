/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:49:49 by linux             #+#    #+#             */
/*   Updated: 2025/02/26 23:51:03 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*philo_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;

	printf("Philo routine\n");
	return (NULL);
}
