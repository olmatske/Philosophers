/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:27:02 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/13 19:58:30 by olmatske         ###   ########.fr       */
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
	if (philo->table->total_philos == 1)
	{
		printft(philo->table, philo, FORK);
		usleep(philo->table->ttd * 1000);
		philo->table->dead_philo++;
		printft(philo->table, philo, DEATH);
		return (NULL);
	}
	if (philo->index % 2)
		usleep(1000);
	while (philo->is_alive == 1 && philo->table->dead_philo == 0)
	{
		ft_eat(philo);
		if (check_death(philo->table->philos, philo->table, philo->index - 1) > 0)
			return (NULL);
		ft_sleep(philo);
		if (check_death(philo->table->philos, philo->table, philo->index - 1) > 0)
			return (NULL) ;
		ft_think(philo);
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
	philo->time_since_eaten = get_time();
	usleep(philo->table->tte * 1000);
	philo->meal_count += 1;
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
