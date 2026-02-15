/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:27:02 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/15 15:02:14 by olmatske         ###   ########.fr       */
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
		philo->table->dead_philo++;
		printft(philo->table, philo, DEATH);
		return (NULL);
	}
	if (philo->index % 2)
		usleep(1000);
	while (!stop(philo->table))
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
	pthread_mutex_lock(&philo->table->death);
	philo->time_since_eaten = get_time();
	pthread_mutex_unlock(&philo->table->death);
	smart_sleep(philo->table, philo->table->tte);
	philo->meal_count += 1;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	ft_sleep(t_philo *philo)
{
	(void)philo;
	printft(philo->table, philo, SLEEP);
	smart_sleep(philo->table, philo->table->tts);
}

void	ft_think(t_philo *philo)
{
	printft(philo->table, philo, THINK);
}
