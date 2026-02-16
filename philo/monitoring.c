/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/16 17:00:41 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo, t_table *table)
{
	int	i;
	
	while (!stop(table))
	{
		i = -1;
		while (++i < table->total_philos)
			if (check_death(philo, table, i))
				return ;
		if (table->meals_to_eat != -1 && check_fullness(philo, table))
		{
			pthread_mutex_lock(&table->death);
			table->dead_philo = 1;
			pthread_mutex_unlock(&table->death);
			printf("\nEveryone is full\n\n");
			return ;
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
		&& curr_time - philo[index].time_since_eaten >= table->ttd)
	{
		table->dead_philo = 1;
		death = 1;
	}
	pthread_mutex_unlock(&table->death);
	if (death)
	{
		pthread_mutex_lock(&table->print);
		printf("%lu %d%s\n", curr_time - table->time, philo[index].index, DEATH);
		pthread_mutex_unlock(&table->print);
		return (1);
	}
	return (0);
}

int	check_fullness(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->death);
	while (i < table->total_philos)
	{
		if (philo[i].meal_count < table->meals_to_eat)
		{
			pthread_mutex_unlock(&table->death);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&table->death);
	return (1);
}










