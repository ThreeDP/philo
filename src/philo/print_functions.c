/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:40:02 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/14 20:08:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pmsg(t_philo *p, char *msg)
{
	t_setting	*s;
	long		time;

	p->state = 1;
	s = *get_setting();
	time = elapsed_time(p->init_time);
	pthread_mutex_lock(&s->m_print);
	printf(msg, time, p->name);
	pthread_mutex_unlock(&s->m_print);
}

void	pmsg_die(t_philo *p, char *msg)
{
	t_setting	*s;
	long		time;

	s = *get_setting();
	time = elapsed_time(p->init_time);
	pthread_mutex_lock(&s->m_print);
	printf(msg, time, p->name);
	pthread_mutex_unlock(&s->m_print);
}
