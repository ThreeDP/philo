/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/14 20:08:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_signdetect(int c, long *pos)
{	
	if (c == '-')
		return (*pos += 1, -1);
	else if (c == '+')
		return (*pos += 1, 1);
	return (1);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1 << 10);
	return (0);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1 << 10);
}

long	ft_atol(const char *nptr)
{
	long		pos;
	long		nbr;
	long		sign;

	pos = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	sign = ft_signdetect(nptr[pos], &pos);
	nbr = 0;
	while (ft_isdigit(nptr[pos]))
	{
		nbr *= 10;
		nbr += (nptr[pos] - '0');
		pos++;
	}
	return (nbr * sign);
}
