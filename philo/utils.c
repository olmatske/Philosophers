/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:23:27 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/13 15:49:25 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printft(t_table *table, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&table->print);
	printf("%lu %d%s\n", get_time() - table->time, philo->index, msg);
	pthread_mutex_unlock(&table->print);
}

int	ft_exit(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->total_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		// free(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->death);
	if (table->forks)
		free(table->forks);
	if (philo)
		free(philo);
	if (table)
		free(table);
	return (0);
}



unsigned long	ft_atol(const char *str)
{
	unsigned long	res;
	int		i;
	int		check;

	res = 0;
	check = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check++;
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (check == 2)
		res *= -1;
	return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	check;

	res = 0;
	check = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check++;
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (check == 2)
		res *= -1;
	return (res);
}

