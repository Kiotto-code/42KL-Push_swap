/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:04:47 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:53:50 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortindex(int value, int *sorted, int sort_size)
{
	int	i;

	i = 0;
	while (i < sort_size)
	{
		if (sorted[i] == value)
			return (i);
		i ++;
	}
	return (0);
}

void	ins_sort(t_list **stk_a, int *sorted, int sort_size)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = *stk_a;
	while (cur)
	{
		cur->content->index = sortindex(cur->content->nbr, sorted, sort_size);
		i++;
		cur = cur->next;
	}
}
