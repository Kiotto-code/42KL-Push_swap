/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:22:14 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:54:36 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_head(t_list **stk)
{
	int	max_index;
	int	half_size;

	max_index = get_maxb_index(*stk);
	half_size = ft_lstsize(*stk) / 2;
	if (max_index > half_size)
	{
		while (stk_xsorted(*stk))
		{
			ps_rra(stk);
		}
	}
	else
	{
		while (stk_xsorted(*stk))
		{
			ps_ra(stk);
		}
	}
}

int	*arr_sort(t_list *stk_a)
{
	int		*arr;
	int		i;
	size_t	size;

	size = ft_lstsize(stk_a);
	arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (stk_a)
	{
		arr[i++] = (stk_a->content->nbr);
		stk_a = stk_a->next;
	}
	quicksort(arr, 0, size -1);
	return (arr);
}

void	ps_sort(t_list **stk_a, t_list **stk_b)
{
	t_action	*cheapbook;

	cheapbook = (t_action *)malloc(sizeof(t_action));
	while (*stk_b)
	{
		ps_greedy(stk_a, stk_b, cheapbook);
		if (cheapbook->action == 1)
			ps_action1(stk_a, stk_b, *cheapbook);
		if (cheapbook->action == 2)
			ps_action2(stk_a, stk_b, *cheapbook);
		if (cheapbook->action == 3)
			ps_action3(stk_a, stk_b, *cheapbook);
		if (cheapbook->action == 4)
			ps_action4(stk_a, stk_b, *cheapbook);
		ps_pa(stk_a, stk_b);
	}
	free(cheapbook);
	find_head(stk_a);
}
