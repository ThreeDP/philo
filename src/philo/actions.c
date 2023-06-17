/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:13:21 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/17 15:07:04 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_eat(t_philo *p)
{
	if (lock_eat(p))
		return (1);
	pthread_mutex_lock(&p->m_last_eat);
	p->last_eat = elapsed_time(p->init_time);
	pthread_mutex_unlock(&p->m_last_eat);
	pmsg(p, EAT_MSG);
	usleep((*get_setting())->tm_eat);
	unlock_eat(p);
	pthread_mutex_lock(&p->m_amount_eat);
	p->amount_eat++;
	pthread_mutex_unlock(&p->m_amount_eat);
	return (0);
}

int	start_sleep(t_philo *p)
{
	if (he_is_the_judas())
		return (1);
	pmsg(p, SLEEP_MSG);
	p->state = 0;
	usleep((*get_setting())->tm_sleep);
	return (0);
}

int	start_think(t_philo *p)
{
	if (he_is_the_judas())
		return (1);
	pmsg(p, THINK_MSG);
	return (0);
}

// Find a death philo.
int	he_is_the_judas(void)
{
	pthread_mutex_lock(&(*get_setting())->m_stop);
	if ((*get_setting())->jesus.stop)
	{
		pthread_mutex_unlock(&(*get_setting())->m_stop);
		return (1);
	}
	pthread_mutex_unlock(&(*get_setting())->m_stop);
	return (0);
}
