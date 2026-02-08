/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/08 20:49:20 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// everyoone full, someone died

void	monitoring(t_philo *philo, t_table *table)
{
	unsigned int				i;

	i = 0;
	// printf("\n\nWTF\n\n");
	table->time = get_time();
	while (i < table->total_philos)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	(void)philo;
	while (0)
	{
		if (table->meals_to_eat != (unsigned int)-1
			&& check_fullness(philo, table) == 1)
		{
			printft(table, philo, FULL);
			break ;
		}
		if (philo->time_since_eaten > table->ttd)
			philo->is_alive = -1;
		
	}
}

int	check_fullness(t_philo *philo, t_table *table)
{
	unsigned int	i;
	unsigned int	full;

	i = 0;
	full = 0;
	while (full != table->total_philos)
	{
		if (i == table->total_philos)
			i = 0;
		if (philo[i].meal_count == table->meals_to_eat)
			full++;
		else
			i++;
	}
	return (1);
}










