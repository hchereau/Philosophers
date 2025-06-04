/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:32:29 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 15:59:41 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>

# define MAX_PHILOSOPHERS 200
# define INFINITE_MEALS -1

typedef enum e_state_data
{
	SUCCESS,
	FAILED_VALUE,
	FAILED_MUTEX,
	FAILED_THREAD
}	t_state_data;

typedef enum e_main_state
{
	SUCESS,
	FAILURE,
}	t_main_state;

typedef struct s_data
{
	int		num_philosophers;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		max_meals;
}	t_data;

#endif
