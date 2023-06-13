/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:17:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/12 21:17:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	*get_init_time(void)
{
	static long	time;

	return (&time);
}

t_philo	**get_philo(void)
{
	static t_philo	*p;

	return (&p);
}

t_setting	**get_setting(void)
{
	static t_setting	*s;

	return (&s);
}
