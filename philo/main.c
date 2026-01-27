/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/27 14:46:44 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("%s\n", INVALID), 1);
	if (input_check(argv) != 0)
		return (INVALID, 1);
	printf("good boy\n");
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

