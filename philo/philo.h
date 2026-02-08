/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:49 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/08 19:38:53 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//# LIBRARIES ##################################################################

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

//# ERROR MESSAGES #############################################################

# define INVALID	"Du Hurensohn"
# define INPUT		"Wrong input. Please try again."
# define ERROR		"Problem with blah blah blah"
# define GOOD		"Works"

//# STATE CHANGES ##############################################################

# define FORK		" has taken a fork"
# define EAT		" is eating"
# define THINK		" is thinking"
# define SLEEP		" is sleeping"
# define DEATH		" died"
# define FULL		"Everyone is full"

//# STRUCTS ####################################################################

typedef struct	s_philo {
	pthread_t			thread;
	struct s_table		*table;
	pthread_mutex_t		*lfork;      // left fork of current philo
	pthread_mutex_t		*rfork;      // current fork of philo
	unsigned int		index;       // philo index
	unsigned int		meal_count;  // how many meals eaten
	unsigned long		tss;         // time slept
	unsigned long		time_since_eaten;         // time since last eaten check for death
	int					is_alive;    // bool for killing
}	t_philo;

typedef struct	s_table {
	t_philo				*philos;     // array of philos
	pthread_mutex_t		*forks;      // array of fork
	unsigned long		ttd;         // time to die
	unsigned long		tte;         // time to eat
	unsigned long		tts;         // time to sleep
	unsigned int		meals_to_eat;         // MUTEX + ptr???     // number of meals to eat
	pthread_mutex_t		death;
	pthread_mutex_t		print;
	unsigned long		time;
	unsigned int		total_philos;         // number of forks
}	t_table;

//# FUNCTIONS ##################################################################

// main.c //////////////////////////////////////////////////////////////////////
int				main(int argc, char **argv);
unsigned long	get_time(void);

// testing.c ///////////////////////////////////////////////////////////////////
int				test(void);
void			*testfunc(void *arg);
void			*functest(void *arg);

// utils.c /////////////////////////////////////////////////////////////////////
void			printft(t_table *table, t_philo *philo, char *msg);
int				ft_exit(t_philo *philo, t_table *table);
unsigned long	ft_atol(const char *str);
int				ft_atoi(const char *str);

// validate.c //////////////////////////////////////////////////////////////////
int				input_check(char **tokens);
int				ft_isdigit(int a);

// init.c //////////////////////////////////////////////////////////////////////
t_table			*init_table(char **argv);
t_philo			*init_philo(int number_of_philos, t_table *table);

// routine.c ///////////////////////////////////////////////////////////////////
void			*routine(void *arg);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_think(t_philo *philo);

// monitoring.c ////////////////////////////////////////////////////////////////
void			monitoring(t_philo *philo, t_table *table);
int				check_fullness(t_philo *philo, t_table *table);

#endif
