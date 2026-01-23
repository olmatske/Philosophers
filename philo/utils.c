/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:23:27 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/23 18:25:04 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	decimal(const char *str, unsigned long res, int i)
{
	unsigned long	period;

	period = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0') * period;
		period *= 0.1;
		i++;
	}
	return (res);
}

unsigned long	ft_atol(const char *str)
{
	unsigned long	res;
	int		i;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		res = decimal(str, res, ++i);
	return (res *= sign, res);
}





pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* trythis(void* arg) 
{
	pthread_mutex_lock(&lock);
	counter += 1;
	printf("Job %d started\n", counter);
	for (unsigned long i = 0; i < 0xFFFFFFFF; i++);
	printf("Job %d finished\n", counter);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
	pthread_mutex_init(&lock, NULL);
	for (int i = 0; i < 2; i++)
		pthread_create(&tid[i], NULL, trythis, NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}