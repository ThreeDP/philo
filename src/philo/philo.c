/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:19:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/12 21:15:46 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_setting	*s;
	t_philo		*p;

	s = NULL;
	if (ac >= 5 && ac <= 6)
	{
		s = start_setting(ac, av);
		p = the_lords_supper(s);
		clean_all(s, p);
		return (0);
	}
	printf("extra number of arguments\n");
	return (0);
}
