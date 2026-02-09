/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/09 16:40:48 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// everyoone full, someone died

void	monitoring(t_philo *philo, t_table *table)
{
	unsigned int				i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	table->time = get_time();
	while (1)
	{
		if (table->meals_to_eat != (unsigned int)-1
			&& check_fullness(philo, table) == 1)
		{
			i = 0;
			while(i < table->total_philos)
				philo[i++].is_alive = 1;
			printft(table, philo, FULL);
			break ;
		}
		if (check_death(philo, table) == 1)
		{
			philo->is_alive = -1,
			ft_exit(philo, table);
			printft(table, philo, DEATH);
			exit (0);
		}
	}
}

int	check_death(t_philo *philo, t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->total_philos)
	{
		if (philo->time_since_eaten >= (table->time - table->ttd))
			return (1);
		i++;
	}
	return (0);
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










