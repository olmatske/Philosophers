/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/12 14:48:42 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// do I have to create a new thread?

void	monitoring(t_philo *philo, t_table *table)
{
	int	i;

	i = -1;
	// while (++i < table->total_philos)
	// 	pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
	table->time = get_time();
	while (table->dead_philo == 0)
	{
		if (table->meals_to_eat != -1
			&& check_fullness(philo, table) == 1)
		{
			i = -1;
			while(++i < table->total_philos)
				philo[i].is_alive = check_death(philo, table, i);
			printft(table, philo, FULL);
			break ;
		}
	}
}

int	check_death(t_philo *philo, t_table *table, unsigned int index)
{
	unsigned long	curr_time;

	curr_time = get_time();
	pthread_mutex_lock(&table->death);
	if (philo[index].time_since_eaten >= curr_time - table->ttd)
	{
		philo[index].is_alive = -1;
		table->dead_philo++;
	}
	pthread_mutex_unlock(&table->death);
	return (table->dead_philo);
}

int	check_fullness(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		if (philo[i].meal_count < table->meals_to_eat)
			return (0);
		i++;
	}
	return (1);
}










