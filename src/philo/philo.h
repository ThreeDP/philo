#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval  t_time;
typedef pthread_mutex_t t_mutex;

typedef struct s_setting
{
    int     num_philos;
    int     tm_die;
    int     tm_eat;
    int     tm_sleep;
    int     num_tm_eat;
}           t_setting;

typedef struct s_philo
{
    pthread_t   th_id;
    long        amount_eat;
    long        last_eat;
    t_mutex     left_fork;
    t_mutex     rigth_fork;
}               t_philo;

typedef struct s_data
{
    long        tmp;
    long        tm_now;
}               t_data;

# define DIE_MSG "%i %i died\n"
# define EAT_MSG "%i %i is eating\n"
# define THINK_MSG "%i %i is thinking\n"
# define SLEEP_MSG "%i %i is sleeping\n"
# define FORK_MSG "%i %i has taken a fork\n"

long        *get_init_time();
#endif