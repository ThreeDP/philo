/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:57:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/15 15:57:01 by dapaulin         ###   ########.fr       */
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
	if (one_philo(s, p))
	{
		i = -1;
		while (++i < s->num_philos)
			pthread_create(&p[i].th_id, NULL, &bread_and_wine, &p[i]);
		i = 0;
		while (i < s->num_philos)
			pthread_join(p[i++].th_id, NULL);
	}
	pthread_join(s->jesus.id, NULL);
	return (p);
}

void	*watching_life(void *set)
{
	int			i;
	t_setting	*s;
	t_philo		*p;
	int			num_philos;
	int			num_tm_eat;

	i = 0;
	p = *get_philo();
	s = (t_setting *)set;
	num_tm_eat = s->num_tm_eat;
	num_philos = s->num_philos;
	while (1)
	{
		i = 0;
		while (i < num_philos)
		{
			count_meals(s, &p[i], num_tm_eat);
			if (num_tm_eat >= 0)
			{
				if (end_the_supper(s, num_philos))
					return (NULL);
				if (disciple_is_dead(s, &p[i], s->tm_die))
					return (NULL);
			}
			i++;
		}
		usleep(5000);
	}
	return (NULL);
}
