/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:19:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/05/31 23:24:01 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setting	*start_setting(int ac, char **av)
{
    t_setting	*s;

    s = malloc(sizeof(t_setting));
    memset(s, 0, sizeof(t_setting));
    s->num_philos = atoi(av[1]);
    s->tm_die = atoi(av[2]);
    s->tm_eat = atoi(av[3]);
    s->tm_sleep = atoi(av[4]);
    if (ac == 6)
	   s->num_tm_eat = atoi(av[5]);
    return (s);
}

void	clean_all(t_setting *s)
{
	if (s)
		free(s);
}

int	main(int ac, char **av)
{
	t_setting	*s;

	s = NULL;
	if (ac >= 5 && ac <= 6)
	{
		s = start_setting(ac, av);
		clean_all(s);
		return (0);
	}
	printf("extra number of arguments\n");
	return (0);
	(void)s;
}