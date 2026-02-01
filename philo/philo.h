/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:49 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/01 17:00:43 by olmatske         ###   ########.fr       */
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
	unsigned long		tse;         // time since last eaten check for death
	unsigned long		tss;         // time to sleep
	int					is_alive;    // bool for killing
}	t_philo;

typedef struct	s_table {
	t_philo				*philos;     // list of philos
	pthread_mutex_t		*forks;      // list of forks
	pthread_mutex_t		death;
	pthread_mutex_t		print;
	unsigned long		ttd;         // time to die
	unsigned long		tte;         // time to eat
	unsigned long		tts;         // time to sleep
	int					nom;         // number of meals to eat
	// int					nof;         // number of forks
}	t_table;

//# FUNCTIONS ##################################################################

// main.c //////////////////////////////////////////////////////////////////////
int				main(int argc, char **argv);
unsigned long	gtd(void);
void	free_philo(t_philo **philo);

// testing.c ///////////////////////////////////////////////////////////////////
int				test(void);
void			*testfunc(void *arg);
void			*functest(void *arg);

// utils.c /////////////////////////////////////////////////////////////////////
unsigned long	ft_atol(const char *str);
int	ft_atoi(const char *str);

// validate.c //////////////////////////////////////////////////////////////////
int	input_check(char **tokens);
int	ft_isdigit(int a);


void	init_wrapper(char **argv, t_philo *philo);
// void	init_table(int philos, unsigned long die, unsigned long eat,
// 		unsigned long sleep, int meals);
t_philo	*init_philo(int number_of_philos, t_philo *philo);



#endif
