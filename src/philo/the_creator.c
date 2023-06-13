/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:57:55 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/13 11:08:44 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *watching_life(void  *s)
{
    *get_init_time() = tm_now();
    while (!((t_setting *)s)->jesus.end)
    {
        *get_time_now() = elapsed_time();
        usleep(5 / 100000);
    }
    return (NULL);
    (void)s;
}