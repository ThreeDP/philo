#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_setting
{
    int     num_philos;
    int     tm_die;
    int     tm_eat;
    int     tm_sleep;
    int     num_tm_eat;
}           t_setting;

# define DIE_MSG "%i %i died\n"
# define EAT_MSG "%i %i is eating\n"
# define THINK_MSG "%i %i is thinking\n"
# define SLEEP_MSG "%i %i is sleeping\n"
# define FORK_MSG "%i %i has taken a fork\n"

#endif