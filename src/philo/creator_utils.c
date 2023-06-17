/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:17:46 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/15 17:53:29 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sad_man(void *p)
{
	pmsg(p, THINK_MSG);
	while (1)
	{
		usleep(5000);
		if (he_is_the_judas())
			return (NULL);
	}
	return (NULL);
}

int	one_philo(t_setting *s, t_philo *p)
{
	if (s->num_philos != 1)
		return (1);
	pthread_create(&p[0].th_id, NULL, &sad_man, &p[0]);
	pthread_join(p[0].th_id, NULL);
	return (0);
}

int	end_the_supper(t_setting *s, long num_philos)
{
	if (s->jesus.amount_eat == num_philos)
	{
		pthread_mutex_lock(&s->m_stop);
		s->jesus.stop = 1;
		pthread_mutex_unlock(&s->m_stop);
		return (1);
	}
	return (0);
}

void	count_meals(t_setting *s, t_philo *disciple, long amount_eat)
{	
	pthread_mutex_lock(&disciple->m_amount_eat);
	if (!disciple->wine && disciple->amount_eat == amount_eat)
	{
		disciple->wine = 1;
		pthread_mutex_unlock(&disciple->m_amount_eat);
		s->jesus.amount_eat += 1;
	}
	else
		pthread_mutex_unlock(&disciple->m_amount_eat);
}

int	disciple_is_dead(t_setting *s, t_philo *p, long time_die)
{
	pthread_mutex_lock(&p->m_last_eat);
	if ((elapsed_time(s->jesus.time_init) - \
	p->last_eat > time_die / 1000))
	{
		pthread_mutex_unlock(&p->m_last_eat);
		pthread_mutex_lock(&s->m_stop);
		s->jesus.stop = 1;
		pthread_mutex_unlock(&s->m_stop);
		pmsg_die(p, DIE_MSG);
		return (1);
	}
	else
		pthread_mutex_unlock(&p->m_last_eat);
	return (0);
}
