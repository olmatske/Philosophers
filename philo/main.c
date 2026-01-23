/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/23 14:02:57 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*testfunc(void *arg)
{
	(void)arg;
	unsigned long	start;
	unsigned long	timer;
	start = gtd();
	while (1)
	{
		timer = gtd() - start;
		printf("%li\n", timer);
		sleep(1);
		// usleep(8 * 1000);
	}
	return NULL;
}

void	*functest(void *arg)
{
	(void)arg;
	unsigned long	start;
	unsigned long	timer;
	start = gtd();
	while (1)
	{
		timer = gtd() - start;
		printf("Second Thread\n");
		sleep(1);
		// usleep(8 * 1000);
	}
	return NULL;
}


int main (void)
{
	pthread_t	thread_1;
	pthread_t	thread_2;
	pthread_create(&thread_1, NULL, testfunc, NULL);
	pthread_create(&thread_2, NULL, functest, NULL);
	sleep(6);
	pthread_cancel(thread_1);
	pthread_cancel(thread_2);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	printf("done\n");
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	(void) argv;
// 	unsigned long	start;
// 	unsigned long	timer;
// 	// const int	number_of_philosophers = ft_atol(argv[1]);
// int	main(int argc, char **argv)
// {
// 	(void) argv;
// 	unsigned long	start;
// 	unsigned long	timer;
// 	// const int	number_of_philosophers = ft_atol(argv[1]);
// 	// const int	time_to_die = ft_atol(argv[2]);
// 	// const int	time_to_eat = ft_atol(argv[3]);
// 	// const int	time_to_sleep = ft_atol(argv[4]);
// 	// const int 	number_of_times_each_philosopher_must_eat;

// 	if (argc != 5 && argc != 6)
// 		return (printf("%s\n", INVALID), 1);
// 	else
// 	{
// 		// start = gtd();
// 		// while (1)
// 		// {
// 		// 	timer = gtd() - start;
// 		// 	printf("%li\n", timer);
// 		// 	sleep(1);
// 		// 	// usleep(8 * 1000);
// 		// }
// 		return (0);
// 	}
// 	// const int	time_to_die = ft_atol(argv[2]);
// 	// const int	time_to_eat = ft_atol(argv[3]);
// 	// const int	time_to_sleep = ft_atol(argv[4]);
// 	// const int 	number_of_times_each_philosopher_must_eat;

// 	if (argc != 5 && argc != 6)
// 		return (printf("%s\n", INVALID), 1);
// 	else
// 	{
// 		// start = gtd();
// 		// while (1)
// 		// {
// 		// 	timer = gtd() - start;
// 		// 	printf("%li\n", timer);
// 		// 	sleep(1);
// 		// 	// usleep(8 * 1000);
// 		// }
// 		return (0);
// 	}
// }

unsigned long	gtd(void)
{
	unsigned long	time;

	gettimeofday(&tv, NULL);
	// time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = tv.tv_sec;
	return (time);
}

