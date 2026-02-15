/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:16:11 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/15 15:13:10 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_full(t_philo *philo)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < philo->table->total_philos)
	{
		printf("Philo %d has eaten %d itmes\n", philo[i].index, philo[i].meal_count);
		i++;
	}
}

void	smart_sleep(t_table *table, unsigned long ms)
{
	unsigned long	start = get_time();
	while (!stop(table) && get_time() - start < ms)
		usleep(200);
}

void	printft(t_table *table, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&table->print);
	if (stop(table) && ft_strncmp(msg, DEATH) && ft_strncmp(msg, FULL))
	{
		pthread_mutex_unlock(&table->print);
		return ;
	}
	printf("%lu %d%s\n", get_time() - table->time, philo->index, msg);
	pthread_mutex_unlock(&table->print);
}

int	ft_exit(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	print_full(philo);
	while (i < table->total_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->total_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
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
