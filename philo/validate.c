/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/27 18:24:15 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(char **tokens)
{
	int		i;
	int		k;
	long	n;

	k = 1;
	while (tokens[k])
	{
		i = 0;
		if (tokens[k][i] == '-')
			return (printf("%s\n", INPUT), 1);
		if (tokens[k][i] == '+')
			i++;
		while (tokens[k][i])
		{
			if (ft_isdigit((unsigned char)tokens[k][i]) == 0)
				return (printf("%s\n", INPUT), 1);
			i++;
		}
		n = ft_atol(tokens[k]);
		if (n > INT_MAX)
			return (printf("%s\n", INPUT), 1);
		k++;
	}
	return (0);
}

int	ft_isdigit(int a)
{
	return (a >= '0' && a <= '9');
}
