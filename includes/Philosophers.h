/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:32:29 by linux             #+#    #+#             */
/*   Updated: 2025/06/04 15:03:08 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>

typedef enum e_state_data
{
	SUCCESS,
	FAILED_MALLOC,
	FAILED_MUTEX,
	FAILED_THREAD
}	t_state_data;

typedef struct s_data
{

}	t_data;

#endif
