/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/01 19:56:33 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//circly linked list

// void	init_thread(int	num)
// {
// 	pthread_create()
// }

void	init_forks(t_philo *philo, int id, int number_of_philos)
{
	if (!(number_of_philos % 2))
	{
		philo[id].lfork = 
	}
}

t_table	*init_table(char **argv, t_philo *philo, t_table *table, int meals)
{
	table = malloc(sizeof(t_table));
	
	table->philos = philo;
	// table->forks = forks;
	table->ttd = ft_atol(argv[2]);
	table->tte = ft_atol(argv[3]);
	table->tts = ft_atol(argv[4]);
	table->nom = meals;
	

	// init_philo(number_of_philos, philo);
	return (table);
}

t_philo	*init_philo(int number_of_philos, t_philo *philo, t_table *table)
{
	int	id;

	id = 0;
	philo = malloc(sizeof(t_philo) * number_of_philos);
	memset(philo, 0, sizeof(t_philo) * number_of_philos);
	while (id < number_of_philos)
	{
		philo[id].index = id;
		philo[id].meal_count = 0;
		philo[id].tse = 0;
		philo[id].tss = 0;
		philo[id].is_alive = 1; 
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


