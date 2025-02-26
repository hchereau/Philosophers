/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:29:42 by linux             #+#    #+#             */
/*   Updated: 2025/02/26 23:55:41 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_state_functions	init_data(int argc, char **argv, t_data *data)
{
	get_args(argc, argv, data);
	if (init_mutex(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(argc - 1, argv + 1, &data) == FAILURE)
		return (FAILURE);
	core_routine(&data);
	return (SUCCESS);

}
