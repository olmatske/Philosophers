/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:27:02 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/16 20:49:27 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->total_philos == 1)
	{
		printft(philo->table, philo, FORK);
		smart_sleep(philo->table, philo->table->ttd);
		pthread_mutex_lock(&philo->table->death);
		philo->table->dead_philo++;
		pthread_mutex_unlock(&philo->table->death);
		printft(philo->table, philo, DEATH);
		return (NULL);
	}
	if (philo->index % 2)
		usleep(1000);
	while (!stop(philo->table))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	printft(philo->table, philo, FORK);
	pthread_mutex_lock(philo->rfork);
	printft(philo->table, philo, FORK);
	printft(philo->table, philo, EAT);
	smart_sleep(philo->table, philo->table->tte);
	pthread_mutex_lock(&philo->table->activity);
	philo->time_since_eaten = get_time();
	philo->meal_count += 1;
	pthread_mutex_unlock(&philo->table->activity);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void	ft_sleep(t_philo *philo)
{
	(void)philo;
	printft(philo->table, philo, SLEEP);
	smart_sleep(philo->table, philo->table->tts);
}

void	ft_think(t_philo *philo)
{
	long	think_time;

	printft(philo->table, philo, THINK);
	if (philo->table->total_philos % 2 == 1)
	{
		think_time = (long)philo->table->tte * 2 - (long)philo->table->tts;
		if (think_time < 0)
			think_time = 0;
		smart_sleep(philo->table, (unsigned long)think_time / 2);
	}
}
