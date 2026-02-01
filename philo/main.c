/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/01 17:06:29 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("%s\n", INVALID), 1);
	// t_table			*table;
	t_philo			*philo;

	if (input_check(argv) != 0)
		return (INVALID, 1);
	// table = NULL;
	philo = init_philo(ft_atoi(argv[1]), NULL);
	printf("good boy\n");
	// monitoring
	return (free(philo), 0);
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

// void	free_philo(t_philo **philo)
// {
// 	t_philo	*tmp;
// 	int		counter;

// 	tmp = (*philo);
// 	counter = 0;
// 	while (*philo)
// 	{
// 		tmp = philo[counter];
// 		free(philo[counter]);
// 		philo[counter] = tmp;
// 		counter++;
// 	}
// }