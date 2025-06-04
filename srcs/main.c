/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:20 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 15:07:00 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	if (init_data(&data, argc, argv) != SUCCESS)
	{
		printf("Error: Failed to initialize data.\n");
		return (1);
	}
	if (create_philosophers(&data) != 0)
	{
		printf("Error: Failed to create philosophers.\n");
		return (1);
	}
	start_simulation(&data);
	cleanup(&data);
	return (0);
}
