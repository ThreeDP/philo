/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:13:21 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/13 14:03:26 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philo *p)
{
	lock_eat(p);
	printf_msg(EAT_MSG, p->name);
	p->amount_eat++;
	usleep((*get_setting())->tm_eat);
	unlock_eat(p);
}

void	start_sleep(t_philo *p)
{
	//pthread_mutex_lock(&(*get_setting())->m_sleep);
	printf_msg(SLEEP_MSG, p->name);
	usleep((*get_setting())->tm_sleep);
	//pthread_mutex_unlock(&(*get_setting())->m_sleep);
}

void	start_think(t_philo *p)
{
	printf_msg(THINK_MSG, p->name);
}

// Find a death philo.
void	he_is_not_the_judas(void)
{
	printf(DIE_MSG, tm_now() - *get_init_time(), (*get_philo())->name);
}
