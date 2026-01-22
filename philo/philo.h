/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:49 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/22 18:24:44 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

# define INVALID	"Du Hurensohn"

# define FORK		" has taken a fork"
# define EAT		" is eating"
# define THINK		" is thinking"
# define SLEEP		" is sleeping"

struct timeval tv;

typedef struct	s_table {
	int	forks;
} t_table;

typedef struct	s_philo {
	int	id;
	int	meals;
	unsigned long	time_slept;
	unsigned long	time_thought;
	unsigned long	time_ate;
	t_table	*left;
	t_table	*right;
}	t_philo;

int main(int argc, char **argv);
unsigned long	gtd(void);

unsigned long	decimal(const char *str, unsigned long res, int i);
unsigned long	ft_atol(const char *str);


#endif
