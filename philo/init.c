/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:25:35 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/28 18:47:58 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//circly linked list

// void	init_thread(int	num)
// {
// 	pthread_create()
// }

void	init_table(char **argv)
{

}

// circly linked list
void	init_philo(char **argv)
{
	int	i;
	int	counter;
	t_philo	**philo;

	counter = 0;
	i = argv[1];
	philo = NULL;
	philo = malloc(sizeof(t_philo) * i);
	while(philo->index < i)
	{
		
	}
}

void	init_forks(int num)
{
	
}