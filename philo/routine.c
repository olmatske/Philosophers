/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:27:02 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/08 15:10:09 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//eat, sleep, think, repeat
//think if no fork available



// take lfork, take rfork, eat, sleep
// if fork is locked, philosopher is stuck, therefore he thinks
// think if mutex locked

// fullness by checking first instance of total philo fullness % meals to eat = 0

// individual fucntions for checking mutexes: death, print, forks

#include "philo.h"

void	routine(t_philo **philo, t_table *table)
{
	ft_eat(philo, table);
	ft_sleep(philo, table);
	ft_think(philo, table);
}

void	ft_eat(t_philo **philo, t_table *table)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
	usleep(table->tte);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	ft_sleep(t_philo **philo, t_table *table)
{
	(void)philo;
	usleep(table->tts);
}

void	ft_think(t_philo **philo, t_table *table)
{
	printft(table, philo, THINK);
}

void	printft(t_table *table, t_philo **philo, char *msg)
{
	pthread_mutex_lock(&table->print);
	printf("%lu %d %s", table->time, philo->index, msg);
	pthread_mutex_unlock(&table->print);
}
