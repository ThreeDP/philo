/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:57:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/14 20:24:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Run a thread.
static void	*bread_and_wine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->name % 2 != 0)
	{
		start_think(p);
		usleep(1000);
	}
	while (1)
	{
		if (start_eat(p))
			break ;
		if (start_sleep(p))
			break ;
		if (start_think(p))
			break ;
	}
	return (NULL);
}

// Starts the philos dinner.
t_philo	*the_lords_supper(t_setting *s)
{
	int		i;
	t_philo	*p;

	p = set_the_supper_table(s->num_philos, s->forks);
	i = -1;
	s->jesus.time_init = tm_now();
	while (++i < s->num_philos)
		p[i].init_time = s->jesus.time_init;
	pthread_create(&s->jesus.id, NULL, &watching_life, s);
	i = -1;
	while (++i < s->num_philos)
		pthread_create(&p[i].th_id, NULL, &bread_and_wine, &p[i]);
	i = 0;
	while (i < s->num_philos)
		pthread_join(p[i++].th_id, NULL);
	pthread_join(s->jesus.id, NULL);
	return (p);
}

void	*watching_life(void *set)
{
	int			i;
	t_setting	*s;
	t_philo		*p;
	long		amount_eat;
	long		time_die;

	i = 0;
	p = *get_philo();
	s = (t_setting *)set;
	amount_eat = s->num_tm_eat;
	time_die = s->tm_die;
	while (1)
	{
		i = 0;
		while (i < s->num_philos)
		{
			pthread_mutex_lock(&p[i].m_last_eat);
			if (p[i].amount_eat == amount_eat)
			{
				pthread_mutex_unlock(&p[i].m_last_eat);
				s->jesus.amount_eat += 1;
			}
			else
				pthread_mutex_unlock(&p[i].m_last_eat);
			if (s->jesus.amount_eat == amount_eat)
			{
				pthread_mutex_lock(&s->m_stop);
				s->jesus.stop = 1;
				pthread_mutex_unlock(&s->m_stop);
				return (NULL);
			}
			pthread_mutex_lock(&p[i].m_last_eat);
			if ((elapsed_time(s->jesus.time_init) - \
			p[i].last_eat > time_die / 1000))
			{
				pthread_mutex_unlock(&p[i].m_last_eat);
				pthread_mutex_lock(&s->m_stop);
				s->jesus.stop = 1;
				pthread_mutex_unlock(&s->m_stop);
				pmsg_die(p, DIE_MSG);
				return (NULL);
			}
			else
				pthread_mutex_unlock(&p[i].m_last_eat);
			i++;
		}
		usleep(8000);
	}
	return (NULL);
}
