/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:20:57 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/12 21:15:01 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	tm_now(void)
{
	t_time	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	printf_msg(char *msg, int id)
{
	pthread_mutex_lock(&(*get_setting())->m_print);
	printf(msg, tm_now() - *get_init_time(), id);
	pthread_mutex_unlock(&(*get_setting())->m_print);
}

void	lock_eat(t_philo *p)
{
	if (p->name % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		printf_msg(FORK_MSG, p->name);
		pthread_mutex_lock(p->rigth_fork);
		printf_msg(FORK_MSG, p->name);
		return ;
	}
	pthread_mutex_lock(p->rigth_fork);
	printf_msg(FORK_MSG, p->name);
	pthread_mutex_lock(p->left_fork);
	printf_msg(FORK_MSG, p->name);
}

void	unlock_eat(t_philo *p)
{
	if (p->name % 2 == 0)
	{
		pthread_mutex_unlock(p->rigth_fork);
		pthread_mutex_unlock(p->left_fork);
		return ;
	}
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->rigth_fork);
}
