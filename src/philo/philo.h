/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:11:40 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/15 17:45:01 by dapaulin         ###   ########.fr       */
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

typedef struct s_watch
{
	pthread_t	id;
	int			amount_eat;
	int			stop;
	long		time_init;
}				t_watch;

typedef struct s_setting
{
	int			num_philos;
	int			tm_die;
	int			tm_eat;
	int			tm_sleep;
	int			num_tm_eat;
	t_watch		jesus;
	t_mutex		*forks;
	t_mutex		m_eat;
	t_mutex		m_stop;
	t_mutex		m_print;
}				t_setting;

typedef struct s_philo
{
	pthread_t	th_id;
	int			name;
	int			wine;
	long		amount_eat;
	long		last_eat;
	int			state;
	long		init_time;
	t_mutex		m_last_eat;
	t_mutex		m_amount_eat;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
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

// # define DIE_MSG "%ld %i 💀\033[1;31m died\033[0m\n"
// # define EAT_MSG "%ld %i 🍽️ \033[1;32m is eating\033[0m\n"
// # define THINK_MSG "%ld %i 🤔\033[1;34m is thinking\033[0m\n"
// # define SLEEP_MSG "%ld %i 😴\033[1;35m is sleeping\033[0m\n"
// # define FORK_MSG "%ld %i 🍴\033[1;33m has taken a fork\033[0m\n"

long		ft_atol(const char *nptr);

// SETUP Functions
t_setting	*start_setting(int ac, char **av);
t_philo		*set_the_supper_table(int n_philos, t_mutex *forks);
int			check_args(int ac, char **av);

// The creator
t_philo		*the_lords_supper(t_setting *s);
void		*watching_life(void *s);

// Actions Functions
int			start_eat(t_philo *p);
int			start_sleep(t_philo *p);
int			start_think(t_philo *p);
int			he_is_the_judas(void);

// Print Functions
void		pmsg(t_philo *p, char *msg);
void		pmsg_die(t_philo *p, char *msg);

// CLEAN PHILO
void		destroy_mutexs(t_setting *s);
void		clean_all(t_setting *s, t_philo *p);

// Utils
long		tm_now(void);
long		elapsed_time(long time);
int			lock_eat(t_philo *p);
void		unlock_eat(t_philo *p);

// GET FUNCTIONS
long		*get_init_time(void);
long		*get_time_now(void);
t_philo		**get_philo(void);
t_setting	**get_setting(void);

// CREATOR UTILS
void		*sad_man(void *p);
int			one_philo(t_setting *s, t_philo *p);
int			end_the_supper(t_setting *s, long amount_eat);
void		count_meals(t_setting *s, t_philo *disciple, long amount_eat);
int			disciple_is_dead(t_setting *s, t_philo *p, long time_die);

#endif