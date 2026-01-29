/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/29 14:07:21 by olmatske         ###   ########.fr       */
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

	number_of_philos = ft_atoi(argv[1]);
	time_to_die = ft_atol(argv[2]);
	time_to_eat = ft_atol(argv[3]);
	time_to_sleep = ft_atol(argv[4]);
	if (!argv[5])
		meals = 0;
	else
		meals = ft_atoi(argv[5]);
	init_table(time_to_die, time_to_eat, time_to_sleep, meals);
	init_philo(number_of_philos);

}

void	init_table(int philos, unsigned long die, unsigned long eat,
		unsigned long sleep, int meals)
{
	t_table	*table;

	table = NULL;
	table = malloc(sizeof(t_table));
	table->ttd = die;
	table->tte = eat;
	table->tts = sleep;
	pthread_mutex_init(&table->forks, NULL);
	printf("\nnumber of philos: %d\ndie: %lu\neat: %lu\nsleep: %lu\nmeals: %d\n", philos, die, eat, sleep, meals);
}

// circly linked list
void	init_philo(int philos, t_table table)
{
	t_philo	*philo;
	unsigned long	time_since_eaten;
	unsigned long	time_slept;
	int				id;

	philo = NULL;
	id = 0;
	printf("number of philos: %d\n", philos);
	philo = malloc(sizeof((t_philo *) philos));
	while (id < philos)
	{
		philo
	}
}

// void	init_forks(int num)
// {
	
// }