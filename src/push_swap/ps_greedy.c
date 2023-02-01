/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:28:57 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:54:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_cost(t_action *cheapbook, t_action *cur)
{
	cheapbook->ra = cur->ra;
	cheapbook->rb = cur->rb;
	cheapbook->rra = cur->rra;
	cheapbook->rrb = cur->rrb;
	cheapbook->total = cur->total;
	cheapbook->action = cur->action;
}

void	update_action(t_action *cur)
{
	cur->total = 2147483647;
	if (ft_max(cur->ra, cur->rb) < cur->total)
	{
		cur->total = ft_max(cur->ra, cur->rb);
		cur->action = 1;
	}
	if (ft_max(cur->rra, cur->rrb) < cur->total)
	{
		cur->total = ft_max(cur->rra, cur->rrb);
		cur->action = 2;
	}
	if ((cur->ra + cur->rrb) < cur->total)
	{
		cur->total = cur->ra + cur->rrb;
		cur->action = 3;
	}
	if ((cur->rra + cur->rb) < cur->total)
	{
		cur->total = cur->rra + cur->rb;
		cur->action = 4;
	}
}

void	ps_greedy(t_list **stk_a, t_list **stk_b, t_action *cheapbook)
{
	int			i;
	t_list		*temp;
	t_action	cur;

	i = 0;
	temp = *stk_b;
	cheapbook->total = INT_MAX;
	while (temp)
	{
		cur.ra = get_pusheda_ind(*stk_a, temp);
		cur.rb = i;
		cur.rra = ft_lstsize(*stk_a) - cur.ra;
		cur.rrb = ft_lstsize(*stk_b) - cur.rb;
		update_action(&cur);
		if (cur.total < cheapbook->total)
			update_cost(cheapbook, &cur);
		i++;
		temp = temp->next;
	}
}
