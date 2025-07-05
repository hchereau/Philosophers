/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:20 by linux             #+#    #+#             */
/*   Updated: 2025/07/05 10:07:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philosopher	*philos;
	t_data			*data;
	int				i;
	long			now;
	long			last_meal_time;

	philos = (t_philosopher *)arg;
	data = philos[0].data;
	while (is_simulation_running(data))
	{
		i = 0;
                while (i < data->num_philosophers)
                {
                        now = get_timestamp();
                        pthread_mutex_lock(&data->simulation_mutex);
                        last_meal_time = philos[i].last_meal_time;
                        pthread_mutex_unlock(&data->simulation_mutex);
                        if (now - last_meal_time > data->time_to_die)
                        {
                                print_status(&philos[i], DEAD);
                                pthread_mutex_lock(&data->simulation_mutex);
                                data->simulation_running = 0;
                                pthread_mutex_unlock(&data->simulation_mutex);
                                return (NULL);
                        }
                        i++;
                }
               if (data->max_meals != INFINITE_MEALS)
               {
                       int     j;
                       int     all_full;

                       all_full = 1;
                       j = 0;
                       while (j < data->num_philosophers)
                       {
                               pthread_mutex_lock(&data->simulation_mutex);
                               if (philos[j].meals_eaten < data->max_meals)
                                       all_full = 0;
                               pthread_mutex_unlock(&data->simulation_mutex);
                               if (!all_full)
                                       break ;
                               j++;
                       }
                       if (all_full)
                       {
                               pthread_mutex_lock(&data->simulation_mutex);
                               data->simulation_running = 0;
                               pthread_mutex_unlock(&data->simulation_mutex);
                               return (NULL);
                       }
               }
                usleep(1000);
        }
        return (NULL);
}

static void	start_simulation(t_data *data, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_data			data;
	t_philosopher	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s num_philosophers time_to_die time_to_eat time_to_sleep [max_meals]\n", argv[0]);
		return (FAILURE);
	}
       philos = NULL;
       if (init_data(&data, argc, argv) != SUCCESS_VALUE)
        {
                return (FAILURE);
        }
	data.start_time = get_timestamp();
       if (create_philosophers(&data, &philos) != SUCCESS_VALUE)
        {
                printf("Error: Failed to create philosophers.\n");
                cleanup(&data, NULL);
                return (FAILURE);
        }
        if (pthread_create(&data.monitor_thread, NULL, monitor_routine, philos) != 0)
        {
                printf("Error: Failed to create monitor thread.\n");
                pthread_mutex_lock(&data.simulation_mutex);
                data.simulation_running = 0;
                pthread_mutex_unlock(&data.simulation_mutex);
                start_simulation(&data, philos);
                cleanup(&data, philos);
                return (FAILURE);
        }
        start_simulation(&data, philos);
        pthread_join(data.monitor_thread, NULL);
        cleanup(&data, philos);
	return (SUCCESS);
}
