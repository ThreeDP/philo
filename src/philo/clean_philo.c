/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:09:56 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/12 21:18:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexs(t_setting *s)
{
	int	i;

	i = 0;
	while (i < s->num_philos)
		pthread_mutex_destroy(&s->forks[i++]);
	pthread_mutex_destroy(&s->m_eat);
	pthread_mutex_destroy(&s->m_die);
	pthread_mutex_destroy(&s->m_sleep);
	pthread_mutex_destroy(&s->m_print);
}

void	clean_all(t_setting *s, t_philo *p)
{
	if (p)
		free(p);
	destroy_mutexs(s);
	if (s->forks)
		free(s->forks);
	if (s)
		free(s);
}
