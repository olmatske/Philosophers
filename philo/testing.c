/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:34:54 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/03 17:02:33 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	lock; // works same if lock = fork
int storage = 20;

void	*testfunc(void *arg)
{
	(void)arg;
	unsigned long	start;
	unsigned long	timer;
	start = gtd();
	while (1)
	{	
		timer = gtd() - start;
		pthread_mutex_lock(&lock);
		printf("%li\n", timer);
		pthread_mutex_unlock(&lock);
		usleep(100 * 1000);
	}
	return NULL;
}

void	*functest(void *arg)
{
	(void)arg;
	int	i = 0;
	unsigned long	start;
	unsigned long	timer;
	start = gtd();
	while (1)
	{
		timer = gtd() - start;
		pthread_mutex_lock(&lock);
		printf("%d Thread\n", i++);
		pthread_mutex_unlock(&lock);
		usleep(100 * 1000);
	}
	return NULL;
}


int test (void)
{
	pthread_t	thread_1;
	pthread_t	thread_2;


	pthread_mutex_init(&lock, NULL);
	pthread_create(&thread_1, NULL, testfunc, NULL);
	pthread_create(&thread_2, NULL, functest, NULL);
	sleep(1);
	pthread_cancel(thread_1);
	pthread_cancel(thread_2);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	printf("done\n");
	return (0);
}