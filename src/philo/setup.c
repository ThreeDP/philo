/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:44:12 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/12 21:27:57 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setting	*start_setting(int ac, char **av)
{
	int			i;
	t_setting	*s;

	s = malloc(sizeof(t_setting));
	memset(s, 0, sizeof(t_setting));
	s->num_philos = atoi(av[1]);
	s->tm_die = atoi(av[2]) * 1000;
	s->tm_eat = atoi(av[3]) * 1000;
	s->tm_sleep = atoi(av[4]) * 1000;
	if (ac == 6)
		s->num_tm_eat = atoi(av[5]);
	s->forks = malloc(sizeof(t_mutex) * s->num_philos);
	memset(s->forks, 0, sizeof(t_mutex) * s->num_philos);
	i = 0;
	while (i < s->num_philos)
		pthread_mutex_init(&s->forks[i++], NULL);
	pthread_mutex_init(&s->m_die, NULL);
	pthread_mutex_init(&s->m_eat, NULL);
	pthread_mutex_init(&s->m_sleep, NULL);
	*get_setting() = s;
	return (s);
}

t_philo	*set_the_supper_table(int n_philos, t_mutex *forks)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = malloc(sizeof(t_philo) * n_philos);
	memset(p, 0, sizeof(t_philo) * n_philos);
	while (i < n_philos)
	{
		p[i].name = i + 1;
		if (i == n_philos - 1)
		{
			p[i].left_fork = &forks[i];
			p[i].rigth_fork = &forks[0];
			break ;
		}
		p[i].left_fork = &forks[i];
		p[i].rigth_fork = &forks[i + 1];
		i++;
	}
	*get_philo() = p;
	return (p);
}

// Run a thread.
static void	*bread_and_wine(void *p)
{
	while (1)
	{
		start_eat(p);
		if (((t_philo *)p)->amount_eat == (*get_setting())->num_tm_eat)
			break ;
		start_sleep(p);
		start_think(p);
	}
	return (NULL);
}

// Starts the philos dinner.
t_philo	*the_lords_supper(t_setting *s)
{
	int		i;
	t_philo	*p;

	i = -1;
	p = set_the_supper_table(s->num_philos, s->forks);
	*get_init_time() = tm_now();
	while (++i < s->num_philos)
		pthread_create(&p[i].th_id, NULL, &bread_and_wine, &p[i]);
	i = 0;
	while (i < s->num_philos)
		pthread_join(p[i++].th_id, NULL);
	return (p);
}
