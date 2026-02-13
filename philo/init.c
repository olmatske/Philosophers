/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/12 14:42:30 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(pthread_mutex_t *forks, t_philo *philo, int id, int ph_len)
{
	if (ph_len == 1)
	{
		philo->lfork = &forks[id];
		philo->rfork = NULL;
	}
	if (!(id % 2))
	{
		philo->lfork = &forks[id];
		philo->rfork = &forks[(id + 1) % ph_len];
	}
	else
	{
		philo->rfork = &forks[id];
		philo->lfork = &forks[(id + 1) % ph_len];
	}
}

t_table	*init_table(char **argv)
{
	t_table			*table;
	int	i;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philos = NULL;
	table->total_philos = ft_atoi(argv[1]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->total_philos);
	while (i < table->total_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->death, NULL);
	table->time = get_time();
	table->ttd = ft_atol(argv[2]);
	table->tte = ft_atol(argv[3]);
	table->tts = ft_atol(argv[4]);
	
	// table->time = get_time();
	if (!argv[5])
		table->meals_to_eat = -1;
	else
		table->meals_to_eat = ft_atoi(argv[5]);
	return (table);
}

t_philo	*init_philo(int number_of_philos, t_table *table)
{
	t_philo	*philo;
	int		id;

	philo = malloc(sizeof(t_philo) * number_of_philos);
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo) * number_of_philos);
	id = 0;
	while (id < number_of_philos)
	{
		philo[id].index = id + 1;
		philo[id].table = table;
		philo[id].meal_count = 0;
		philo[id].time_since_eaten = table->time;
		philo[id].tss = 0;
		philo[id].is_alive = 1;
		init_forks(table->forks, &philo[id], id, number_of_philos);
		id++;
	}
	return (philo);
}
