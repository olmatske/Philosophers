/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/08 15:10:09 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(pthread_mutex_t *forks, t_philo **philo, int id, int ph_len)
{
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

t_table	*init_table(char **argv, t_philo **philo, t_table *table, int meals)
{
	int	i;

	i = 0;
	table = malloc(sizeof(t_table));
	table->philos = philo;
	table->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
		pthread_mutex_init(&table->forks[i++], NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->death, NULL);
	table->ttd = ft_atol(argv[2]);
	table->tte = ft_atol(argv[3]);
	table->tts = ft_atol(argv[4]);
	table->meals_to_eat = meals;
	table->philos = philo;
	table->total_philos = ft_atoi(argv[1]);
	if (!argv[5])
		table->meals_to_eat = -1;
	else
		table->meals_to_eat = ft_atoi(argv[5]);

	return (table);
}

t_philo	*init_philo(int number_of_philos, t_philo **philo, t_table *table)
{
	int	id;

	id = 0;
	philo = malloc(sizeof(t_philo) * number_of_philos);
	memset(philo, 0, sizeof(t_philo) * number_of_philos);
	printf("\nPHILO:\n");
	while (id < number_of_philos)
	{
		pthread_create(&philo[id], NULL, routine, NULL);
		philo[id].index = id;
		init_forks(table->forks, &philo[id], id, number_of_philos);
		philo[id].meal_count = 0;
		philo[id].time_since_eaten = 0;
		philo[id].tss = 0;
		philo[id].is_alive = 1;
		philo[id].table = table;
		printf("%d\n", philo[id].index);
		id++;
	}
	return(philo);
}
