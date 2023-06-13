/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:19:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/13 12:43:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
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

int	main(int ac, char **av)
{
	t_setting	*s;
	t_philo		*p;

	s = NULL;
	if (ac >= 5 && ac <= 6 && !check_args(ac, av))
	{
		s = start_setting(ac, av);
		p = the_lords_supper(s);
		clean_all(s, p);
		return (0);
	}
	printf("extra number of arguments or invalid argument\n");
	return (0);
}
