/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/01 01:58:41 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("%s\n", INVALID), 1);
	t_table			*table;
	t_philo			*philo[ft_atoi(argv[1])];

	if (input_check(argv) != 0)
		return (INVALID, 1);
	table = NULL;
	init_wrapper(argv, table, *philo);
	printf("good boy\n");
	// monitoring
	return (0);
}

unsigned long	gtd(void)
{
	struct timeval tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	// time = tv.tv_sec;
	return (time);
}

