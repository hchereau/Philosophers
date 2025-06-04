/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:20 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 16:16:48 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

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
	if (create_philosophers(&data, &philos) != 0)
	{
		printf("Error: Failed to create philosophers.\n");
		return (FAILURE);
	}
	start_simulation(&data);
	cleanup(&data);
	return (SUCCESS);
}
