/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:19:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/01 03:54:26 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setting	*start_setting(int ac, char **av)
{
    t_setting	*s;

    s = malloc(sizeof(t_setting));
    memset(s, 0, sizeof(t_setting));
    s->num_philos = atoi(av[1]);
    s->tm_die = atoi(av[2]) * 1000;
    s->tm_eat = atoi(av[3]) * 1000;
    s->tm_sleep = atoi(av[4]) * 1000;
    if (ac == 6)
	   s->num_tm_eat = atoi(av[5]);
    return (s);
}

void	clean_all(t_setting *s, t_philo *p)
{
	if (p)
		free(p);
	if (s)
		free(s);
}

long	tm_now()
{
	t_time	t;

	gettimeofday(&t, NULL);
	return (t.tv_usec / 1000);
}

void	*hello()
{
	printf("Olha ai o que eu achei\n");
	return (NULL);
}

t_philo	*start_philos(t_setting *s)
{
	int		i;
	t_philo	*p;

	p = malloc(sizeof(t_philo) * s->num_philos);
	i = 0;
	while (i < s->num_philos)
	{
		memset(&p[i], 0, sizeof(t_philo));
		pthread_create(&p[i].th_id, NULL, &hello, NULL);
		usleep(s->tm_eat);
		printf("%ld\n", tm_now() - *get_init_time());
		i++;
	}
	i = 0;
	while (i < s->num_philos)
	{
		pthread_join(p[i].th_id, NULL);
		i++;
	}
	return (p);
}

int	main(int ac, char **av)
{
	t_setting	*s;
	t_philo		*p;

	s = NULL;
	if (ac >= 5 && ac <= 6)
	{
		s = start_setting(ac, av);
		*get_init_time() = tm_now();
		printf("%ld\n", *get_init_time() - *get_init_time());
		p = start_philos(s);
		clean_all(s, p);
		return (0);
	}
	printf("extra number of arguments\n");
	return (0);
	(void)s;
	(void)p;
}