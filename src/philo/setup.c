/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:44:12 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/15 17:45:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setting	*start_setting(int ac, char **av)
{
	int			i;
	t_setting	*s;

	s = malloc(sizeof(t_setting));
	memset(s, 0, sizeof(t_setting));
	s->num_philos = ft_atol(av[1]);
	s->tm_die = ft_atol(av[2]) * 1000;
	s->tm_eat = ft_atol(av[3]) * 1000;
	s->tm_sleep = ft_atol(av[4]) * 1000;
	if (ac == 6)
		s->num_tm_eat = ft_atol(av[5]);
	else
		s->num_tm_eat = -1;
	s->forks = malloc(sizeof(t_mutex) * s->num_philos);
	memset(s->forks, 0, sizeof(t_mutex) * s->num_philos);
	i = 0;
	while (i < s->num_philos)
		pthread_mutex_init(&s->forks[i++], NULL);
	pthread_mutex_init(&s->m_eat, NULL);
	pthread_mutex_init(&s->m_stop, NULL);
	pthread_mutex_init(&s->m_print, NULL);
	s->jesus = (t_watch){0};
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
		p[i].wine = 0;
		pthread_mutex_init(&p[i].m_last_eat, NULL);
		pthread_mutex_init(&p[i].m_amount_eat, NULL);
		if (i == n_philos - 1)
		{
			p[i].left_fork = &forks[i];
			p[i].right_fork = &forks[0];
			break ;
		}
		p[i].left_fork = &forks[i];
		p[i].right_fork = &forks[i + 1];
		i++;
	}
	*get_philo() = p;
	return (p);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_atol(av[1]) <= 0)
		return (1);
	if (ac == 6 && ft_atol(av[5]) < 0)
		return (1);
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && (av[i][j] >= '0' && av[i][j] <= '9'))
			j++;
		if (av[i][j])
			return (1);
		i++;
	}
	return (0);
}
