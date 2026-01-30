/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/30 13:49:58 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//circly linked list

// void	init_thread(int	num)
// {
// 	pthread_create()
// }

void	init_wrapper(char **argv, t_table **table, t_philo **philo)
{
	int	meals;

	if (!argv[5])
		meals = -1;
	else
		meals = ft_atoi(argv[5]);

}

void	put_args(char **argv)
{
	int				number_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;


	number_of_philos = ft_atoi(argv[1]);
	time_to_die = ft_atol(argv[2]);
	time_to_eat = ft_atol(argv[3]);
	time_to_sleep = ft_atol(argv[4]);

}

t_table	**init_table(t_table **table, char **argv, int meals)
{
	long	table_index;
	long	len;

	table_index = 0;
	len = 0;
	while (table_index < len)
	{
		table = add_table(table, argv, table_index);
		table_index++;
	}
	return (table);
	printf("\nnumber of philos: %d\ndie: %lu\neat: %lu\nsleep: %lu\nmeals: %d\n", philos, die, eat, sleep, meals);
}

