/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:11:40 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/12 21:23:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;

typedef struct s_setting
{
	int			num_philos;
	int			tm_die;
	int			tm_eat;
	int			tm_sleep;
	int			num_tm_eat;
	t_mutex		*forks;
	t_mutex		m_eat;
	t_mutex		m_sleep;
	t_mutex		m_die;
	t_mutex		m_print;
}				t_setting;

typedef struct s_philo
{
	pthread_t	th_id;
	int			name;
	long		amount_eat;
	long		last_eat;
	t_mutex		*left_fork;
	t_mutex		*rigth_fork;
}				t_philo;

typedef struct s_data
{
	long		tmp;
	long		tm_now;
}				t_data;

# define DIE_MSG "%ld %i died\n"
# define EAT_MSG "%ld %i is eating\n"
# define THINK_MSG "%ld %i is thinking\n"
# define SLEEP_MSG "%ld %i is sleeping\n"
# define FORK_MSG "%ld %i has taken a fork\n"

// Utils
long			tm_now(void);
void			printf_msg(char *msg, int id);
void			lock_eat(t_philo *p);
void			unlock_eat(t_philo *p);

// Actions Functions
void			start_eat(t_philo *p);
void			start_sleep(t_philo *p);
void			start_think(t_philo *p);
void			he_is_not_the_judas(void);

// GET FUNCTIONS
long			*get_init_time(void);
t_philo			**get_philo(void);
t_setting		**get_setting(void);

// CLEAN PHILO
void			destroy_mutexs(t_setting *s);
void			clean_all(t_setting *s, t_philo *p);

// Setup Functions
t_setting		*start_setting(int ac, char **av);
t_philo			*set_the_supper_table(int n_philos, t_mutex *forks);
t_philo			*the_lords_supper(t_setting *s);
#endif