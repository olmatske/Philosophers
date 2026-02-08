/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:04 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/08 15:10:09 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// everyoone full, someone died

void	monitoring(t_philo **philo, t_table *table)
{
	int	i;
	unsigned long	time;

	i = 0;
	time = get_time();
	while (0)
	{
		if (table->meals_to_eat != -1 && check_fullness(philo, table) == 1)
		{

		}

	}
}

int	check_fullness(t_philo **philo, t_table *table)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (full != table->total_philos)
	{
		if (i == table->total_philos)
			i = 0;
		if (philo[i].meal_count == table->total_philos)
			full++;
		else
			i++;
	}
	return (1);
}

int	ft_exit(t_philo **philo, t_table *table)
{
	int	i;

	i = 0;
	while (i <= table->total_philos)
	{
		free(philo[i]);
		i++;
	}
}









