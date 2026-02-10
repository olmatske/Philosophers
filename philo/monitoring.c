/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/10 17:32:18 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// everyoone full, someone died

void	monitoring(t_philo *philo, t_table *table)
{
	unsigned int				i;

	i = 0;
	table->time = get_time();
	while (i < table->total_philos)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	(void)philo;
	while (1)
	{
		if (table->meals_to_eat != (unsigned int)-1
			&& check_fullness(philo, table) == 1)
		{
			i = 0;
			while(i < table->total_philos)
				philo[i++].is_alive = 0;
			printft(table, philo, FULL);
			break ;
		}
		if (philo->time_since_eaten > table->ttd)
			philo->is_alive = -1;
		
	}
}

// void	stop_simulation(t_table *table, t_philo *philo)
// {
	
// }



int	check_death(t_philo *philo, t_table *table)
{
	unsigned long	time;

	pthread_mutex_lock(&table->death);
	time = get_time();
	if ((time - philo->time_since_eaten) > table->ttd)
	{
		table->dead_philo = 1;
		philo->is_alive = -1;
	}
	pthread_mutex_unlock(&table->death);
	return (philo->is_alive);
}


int	check_fullness(t_philo *philo, t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->total_philos)
	{
		if (philo[i].meal_count < table->meals_to_eat)
			return (0);
		i++;
	}
	return (1);
}










