/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:20:57 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/16 19:24:44 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	tm_now(void)
{
	t_time	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

long	elapsed_time(long time)
{
	t_time	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - time);
}

int	lock_eat(t_philo *p)
{
	if (p->name % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
		if (he_is_the_judas())
		{
			unlock_eat(p);
			return (1);
		}
		pmsg(p, FORK_MSG);
		pmsg(p, FORK_MSG);
		return (0);
	}
	pthread_mutex_lock(p->right_fork);
	pthread_mutex_lock(p->left_fork);
	if (he_is_the_judas())
	{
		unlock_eat(p);
		return (1);
	}
	pmsg(p, FORK_MSG);
	pmsg(p, FORK_MSG);
	return (0);
}

void	unlock_eat(t_philo *p)
{
	if (p->name % 2 == 0)
	{
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);
		return ;
	}
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}
