/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/26 17:41:38 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_validate(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	if (argc != 5 && argc != 6)
// 		return (printf("%s\n", INVALID), 1);
// 	while (argv[i] != NULL)
// 	{
// 		if (valid_num == 0)
// 			return (printf("%s\n", INVALID), 1);
// 		else
			
// 	}
// 	return (0);
// }

int	input_check(char **tokens)
{
	int		i;
	int		k;
	long	n;

	while (tokens[k])
	{
		i = 0;
		if (tokens[k][i] == '-' || tokens[k][i] == '+')
			i++;
		if (!tokens[k][i])
			return (1);
		while (tokens[k][i])
		{
			if (!valid_num((unsigned char)tokens[k][i]))
				return (1);
			i++;
		}
		n = ft_atol(tokens[k]);
		if (n > INT_MAX)
			return (1);
		k++;
	}
	return (0);
}

int	valid_num(int a)
{
	return (a >= '0' && a <= '9');
}

// just copy it from push swap at this point -_-


