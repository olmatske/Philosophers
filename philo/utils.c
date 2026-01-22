/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:23:27 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/22 18:24:30 by olmatske         ###   ########.fr       */
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