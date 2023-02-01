/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:22:14 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:53:29 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	inputcheck(char **av)
{
	int	i;
	int	j;

	i = 1;
	if (!av)
		exit(1);
	while (av[i])
	{
		j = 0;
		while ((av[i][j]))
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' '
				|| av[i][j] == '-' || av[i][j] == '+'))
			{
				ft_error("Error");
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_dup(int sorted[], int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (sorted[i] == sorted [i -1])
		{
			ft_error("Error");
		}
		i ++;
	}
}

void	checkmax(long n)
{
	if ((n > 2147483647) || (n < -2147483648))
		ft_error("Error");
}
