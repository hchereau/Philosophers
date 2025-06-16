/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:08:20 by imback            #+#    #+#             */
/*   Updated: 2025/06/08 23:37:02 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	skip_whitespaces(const char **nptr)
{
	while (**nptr == SPACE
		|| (**nptr >= FIRST_WHITESPACE && **nptr <= LAST_WHITESPACE))
	{
		++(*nptr);
	}
}

static int	pop_sign(const char **nptr)
{
	const char	c = **nptr;
	int			sign;

	sign = 1;
	if (c == '-')
	{
		sign = -1;
	}
	*nptr += (c == '+' || c == '-');
	return (sign);
}

static long	convert_str_to_int(const char *nptr)
{
	long	nb;

	nb = 0;
	while (ft_isdigit(*nptr))
	{
		nb = nb * 10 + (*nptr - 48);
		++nptr;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	int	sign;

	skip_whitespaces(&nptr);
	sign = pop_sign(&nptr);
	return (convert_str_to_int(nptr) * sign);
}

/*
	process:
		-> skip whitespace (skip_whitespace)
		-> get sign (get_sign)
		-> convert char to int (convert_char_to_int)

	skip_white:
		->
*/
