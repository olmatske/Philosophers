/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/04 20:15:35 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("%s\n", INVALID), 1);
	t_table			*table;
	t_philo			*philo;
	int				meals;

	if (input_check(argv) != 0)
		return (INVALID, 1);
	if (!argv[5])
		meals = -1;
	else
		meals = ft_atoi(argv[5]);
	philo = NULL;
	table = init_table(argv, philo, NULL, meals);
	philo = init_philo(ft_atoi(argv[1]), NULL, table);
	printf("good boy\n");
	// monitoring
	return (free(philo), free(table), 0);
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
