/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/08 20:27:13 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (printf("%s\n", INVALID), 1);
	if (input_check(argv) != 0)
		return (1);
	table = init_table(argv);
	philo = init_philo(ft_atoi(argv[1]), table);
	table->philos = philo;
	monitoring(philo, table);
	// printf("good boy\n");
	return (ft_exit(philo, table), 0);
}

unsigned long	get_time(void)
{
	struct timeval tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	// time = tv.tv_sec;
	return (time);
}
