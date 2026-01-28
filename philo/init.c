/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/28 22:02:37 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//circly linked list

// void	init_thread(int	num)
// {
// 	pthread_create()
// }

void	init_wrapper(char **argv)
{
	int				number_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				meals;

	number_of_philos = argv[1];
	time_to_die = argv[2];
	time_to_eat = argv[3];
	time_to_sleep = argv[4];
	meals = argv[5];
	init_table(number_of_philos, time_to_die, time_to_eat, time_to_sleep);
	init_philo(number_of_philos, time_to_die, time_to_eat, argv);
}

void	init_table(int philos, unsigned long die, unsigned long eat,
		unsigned long sleep)
{
	t_table	*table;

	table = NULL;
	table = malloc(sizeof(t_table));
	table->ttd = die;
	table->tte = eat;
	table->tts = sleep;
	pthread_mutex_init(&table->forks, NULL);

}

// circly linked list
void	init_philo(int philos)
{
	t_philo	*philo;
	unsigned long	


	philo = NULL;
	philo = ()
}

void	init_forks(int num)
{
	
}