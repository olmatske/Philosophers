/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/01 17:12:52 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//circly linked list

// void	init_thread(int	num)
// {
// 	pthread_create()
// }

void	init_wrapper(char **argv, t_philo *philo)
{
	int				meals;
	int				number_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;

	number_of_philos = ft_atoi(argv[1]);
	time_to_die = ft_atol(argv[2]);
	time_to_eat = ft_atol(argv[3]);
	time_to_sleep = ft_atol(argv[4]);
	if (!argv[5])
		meals = -1;
	else
		meals = ft_atoi(argv[5]);
	// table = malloc(sizeof(t_table));
	
	
	init_philo(number_of_philos, philo);
	// init_table

}

t_philo	*init_philo(int number_of_philos, t_philo *philo)
{
	unsigned long	time_since_eaten;
	unsigned long	time_slept;
	int				id;
	int				meals_eaten;

	id = 0;
	meals_eaten = 0;
	time_since_eaten = -1;
	time_slept = -1;
	philo = malloc(sizeof(t_philo) * number_of_philos);
	memset(philo, 0, sizeof(t_philo) * number_of_philos);
	while (id < number_of_philos)
	{
		philo[id].index = id;
		philo[id].meal_count = meals_eaten;
		philo[id].tse = time_since_eaten;
		philo[id].tss = time_slept;
		printf("%d\n", philo[id].index);
		id++;
	}


	printf("number of philos: %d\n", number_of_philos);
	return(philo);
}

// t_table	**init_table(t_table **table, char **argv, int meals)
// {
// 	long	table_index;
// 	long	len;

// 	table_index = 0;
// 	len = 0;
	
// 	// printf("\nnumber of philos: %d\ndie: %lu\neat: %lu\nsleep: %lu\nmeals: %d\n", philos, die, eat, sleep, meals);
// }

