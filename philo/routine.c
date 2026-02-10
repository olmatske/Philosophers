/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:27:02 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/10 17:04:56 by olmatske         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2)
		usleep(1000);
	while (philo->is_alive == 1)
	{
		ft_eat(philo);
		if (philo->is_alive == 1)
			ft_sleep(philo);
		if (philo->is_alive == 1)
			ft_think(philo);
	}
	if (philo->is_alive == -1)
	{
		printft(philo->table, philo, DEATH);
		ft_exit(philo, philo->table);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
	printft(philo->table, philo, FORK);
	printft(philo->table, philo, FORK);
	printft(philo->table, philo, EAT);
	usleep(philo->table->tte * 1000);
	philo->meal_count += 1;
	// printf("Philo %d has eaten %d meals\n", philo->index, philo->meal_count);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	ft_sleep(t_philo *philo)
{
	(void)philo;
	printft(philo->table, philo, SLEEP);
	usleep(philo->table->tts * 1000);
}

void	ft_think(t_philo *philo)
{
	printft(philo->table, philo, THINK);
}
