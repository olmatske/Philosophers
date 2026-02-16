/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:49 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/16 20:37:44 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//# LIBRARIES ##################################################################

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

//# ERROR MESSAGES #############################################################

# define INVALID	"Please input valid arguments, try: ./philo 5 800 200 200 3"
# define INPUT		"Wrong input. Please try again."
# define ERROR		"Problem with blah blah blah"
# define GOOD		"Works"

//# STATE CHANGES ##############################################################

# define FORK		" has taken a fork"
# define LFORK		" has taken the left fork"
# define RFORK		" has taken the right fork"
# define EAT		" is eating"
# define THINK		" is thinking"
# define SLEEP		" is sleeping"
# define DEATH		" died"
# define FULL		"Everyone is full"

//# STRUCTS ####################################################################

typedef struct s_philo {
	pthread_t			thread;
	struct s_table		*table;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	unsigned int		index;
	int					meal_count;
	unsigned long		tss;
	unsigned long		time_since_eaten;
	int					is_alive;
}	t_philo;

typedef struct s_table {
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		activity;
	unsigned long		ttd;
	unsigned long		tte;
	unsigned long		tts;
	int					meals_to_eat;
	unsigned int		dead_philo;
	pthread_mutex_t		death;
	pthread_mutex_t		print;
	unsigned long		time;
	int					total_philos;
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
int				ft_strncmp(char *first, char *second);
void			printft(t_table *table, t_philo *philo, char *msg);
int				ft_exit(t_philo *philo, t_table *table);

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
int				stop(t_table *table);
int				check_death(t_philo *philo, t_table *table, unsigned int index);
int				check_fullness(t_philo *philo, t_table *table);

// monitornig_utils.c //////////////////////////////////////////////////////////
void			smart_sleep(t_table *table, unsigned long ms);
unsigned long	ft_atol(const char *str);
int				ft_atoi(const char *str);

#endif
