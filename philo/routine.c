/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:27:02 by olmatske          #+#    #+#             */
/*   Updated: 2026/02/04 20:34:54 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//eat, sleep, think, repeat
//think if no fork available



// take lfork, take rfork, eat, sleep
// think if mutex locked

// fullness by checking first instance of total philo fullness % meals to eat = 0

// individual fucntions for checking mutexes: death, print, forks

#include "philo.h"

void	*routine(t_philo *philo, t_table *table)
{
	int	counter;
	unsigned long	think;
	unsigned long	curr_time;

	if (philo[counter].is_alive > -1)
		return (printf("%s\n", DEATH), free(philo), free(table), 1);
	else if (philo->is_full == 1) // how do I check if everyone is full?
		return(printf);

}

// int	check_fullness(t_philo *philo, t_table *table)
// {
// 	int	i;
// 	int	are_full;

// 	i = 0;
// 	are_full = 0;
// 	while (are_full < table->total_philos)
// 	{
// 		philo[i].
// 	}
// }