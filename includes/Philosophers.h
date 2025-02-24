/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:32:29 by linux             #+#    #+#             */
/*   Updated: 2025/02/25 00:00:04 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>

typedef enum e_state_functions
{
	SUCCESS,
	FAILURE
}	t_state_functions;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_count;
	pthread_mutex_t	mutex;
}	t_data;

typedef struct s_philo
{
	int		id;
	int		meal_count;
}	t_philo;

typedef struct s_

#endif
