/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/02 18:35:09 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//circly linked list

// void	init_thread(int	num)
// {
// 	pthread_create()
// }

void	init_forks(pthread_mutex_t *forks , t_philo *philo, int id, int number_of_philos)
{
	if (!(number_of_philos % 2))
	{
		philo->lfork = &forks[id];
		
	}
}

t_table	*init_table(char **argv, t_philo *philo, t_table *table, int meals)
{
	int	i;

	i = 0;
	table = malloc(sizeof(t_table));
	
	table->philos = philo;
	while (i < ft_atoi(argv[1]))
		pthread_mutex_init(&table->forks[i++], NULL);
	// table->forks = forks;
	table->ttd = ft_atol(argv[2]);
	table->tte = ft_atol(argv[3]);
	table->tts = ft_atol(argv[4]);
	table->nom = meals;

	printf("\nTABLE:\nttd: %lu\n", table->ttd);
	printf("tte: %lu\n", table->tte);
	printf("tts: %lu\n", table->tts);
	printf("nom: %d\n", table->nom);
	// init_philo(number_of_philos, philo);
	return (table);
}

t_philo	*init_philo(int number_of_philos, t_philo *philo, t_table *table)
{
	int	id;

	id = 0;
	philo = malloc(sizeof(t_philo) * number_of_philos);
	memset(philo, 0, sizeof(t_philo) * number_of_philos);
	printf("\nPHILO:\n");
	while (id < number_of_philos)
	{
		philo[id].index = id;
		init_forks(forks)
		philo[id].meal_count = 0;
		philo[id].time_since_eaten = 0;
		philo[id].tss = 0;
		philo[id].is_alive = 1; 
		philo[id].table = table;
		printf("%d\n", philo[id].index);
		id++;
	}

	// printf("\n%d\n", philo[id].meal_count);
	// printf("%lu\n", philo[id].tse);
	// printf("%lu\n", philo[id].tss);
	// printf("%d\n", philo[id].is_alive);
	// printf("number of philos: %d\n", number_of_philos);
	return(philo);
}


