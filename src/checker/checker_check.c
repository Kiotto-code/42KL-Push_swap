/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:17:22 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 23:45:36 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
				write(2, "Error\n", 6);
				exit(1);
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
			write(2, "Error\n", 6);
			exit(1);
		}
		i ++;
	}
}

void	checkmax(long n)
{
	if ((n > 2147483647) || (n < -2147483648))
		ft_error("Error");
}

int	stk_xsorted(t_list *stk)
{
	if (!stk)
		ft_error("Error: Nothing to sort");
	while (stk->next)
	{
		if (get_index(stk) > get_index(stk->next))
			return (1);
		stk = stk->next;
	}
	return (0);
}

void	all_sorted(t_list *stk_a, t_list *stk_b)
{
	if (!stk_a)
		ft_error("Error: Nothing to sort\n");
	if (ft_lstsize(stk_b) && !stk_xsorted(stk_a))
	{
		exit(EXIT_SUCCESS);
	}
}
