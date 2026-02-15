/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/15 14:44:14 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo, t_table *table)
{
	int	i;

	i = -1;
	
	while (check_death(philo, table, philo->index) == 0)
	{
		if (table->meals_to_eat != -1
			&& check_fullness(philo, table) == 1)
		{
			i = -1;
			while(++i < table->total_philos)
				philo[i].is_alive = check_death(philo, table, i);
			printf("\nEveryone is full\n\n");
			pthread_mutex_lock(&table->death);
			table->dead_philo = 1;
			pthread_mutex_unlock(&table->death);
			break ;
		}
		if (table->dead_philo != 0)
		{
			ft_exit(philo, table);
		}
		usleep(500);
	}
}

int	stop(t_table *table)
{
	int	stop;

	pthread_mutex_lock(&table->death);
	stop = table->dead_philo > 0;
	pthread_mutex_unlock(&table->death);
	return (stop);
}

int	check_death(t_philo *philo, t_table *table, unsigned int index)
{
	unsigned long	curr_time;
	int				death;

	curr_time = get_time();
	death = 0;
	pthread_mutex_lock(&table->death);
	if (table->dead_philo == 0
		&& curr_time - philo[index].time_since_eaten > table->ttd)
	{
		philo[index].is_alive = -1;
		table->dead_philo++;
		death = 1;
	}
	pthread_mutex_unlock(&table->death);
	if (death)
		printft(table, &philo[index], DEATH);
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










