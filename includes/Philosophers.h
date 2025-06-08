/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:32:29 by linux             #+#    #+#             */
/*   Updated: 2025/06/08 00:43:35 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOSOPHERS 200
# define INFINITE_MEALS -1

/* ENUM */

typedef enum e_state_data
{
	SUCCESS,
	FAILED_VALUE,
}	t_state_data;

typedef enum e_main_state
{
	SUCCESS,
	FAILURE,
}	t_main_state;

typedef enum e_philosopher_state
{
	THINKING,
	FORKS_TAKEN,
	EATING,
	SLEEPING,
	DEAD
}	t_philosopher_state;

/* STRUCT */

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				max_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	long			start_time;
}	t_data;

typedef struct s_philosopher
{
	int					id;
	t_philosopher_state	state;
	int					meals_eaten;
	long				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_forks;
	pthread_mutex_t		*right_forks;
	struct s_data		*data;
}	t_philosopher;

/* PROTOTYPE */

t_state_data	init_data(t_data *data, int argc, char **argv);
int				ft_atoi(const char *nptr);
void			print_status(t_philosopher *philosopher,
					t_philosopher_state state);
t_state_data	create_philosophers(t_data *data, t_philosopher **philos);
long			get_timestamp(void);
void			philosopher_think(t_philosopher *philosopher);
void			try_take_forks(t_philosopher *philosopher);
void			philosopher_eat(t_philosopher *philosopher);
void			return_forks(t_philosopher *philosopher);


#endif
