/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/23 12:53:50 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void) argv;
	unsigned long	start;
	unsigned long	timer;
	// const int	number_of_philosophers = ft_atol(argv[1]);
	// const int	time_to_die = ft_atol(argv[2]);
	// const int	time_to_eat = ft_atol(argv[3]);
	// const int	time_to_sleep = ft_atol(argv[4]);
	// const int 	number_of_times_each_philosopher_must_eat;

	if (argc != 5 && argc != 6)
		return (printf("%s\n", INVALID), 1);
	else
	{
		start = gtd();
		// usleep(8 * 1000);
		while (1)
		{
			timer = gtd() - start;
			printf("%li\n", timer);
			sleep(1);
		}
		// timer = gtd() - start;
		// printf("%li\n", timer);
		return (0);
	}
}

unsigned long	gtd(void)
{
	unsigned long	time;

	gettimeofday(&tv, NULL);
	// time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = tv.tv_sec;
	return (time);
}

