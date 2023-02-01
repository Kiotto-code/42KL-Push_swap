/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:13:30 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:50:22 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_revrotate(t_list **stk)
{
	t_list	*temp;
	t_list	*last;

	temp = *stk;
	last = *stk;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	last->next = *stk;
	*stk = last;
	temp->next = NULL;
}

void	ps_rra(t_list **stk_a)
{
	ps_revrotate(stk_a);
	ft_putendl_fd("rra", 1);
}

void	ps_rrb(t_list **stk_b)
{
	ps_revrotate(stk_b);
	ft_putendl_fd("rrb", 1);
}

void	ps_rrr(t_list **stk_a, t_list **stk_b)
{
	ps_revrotate(stk_a);
	ps_revrotate(stk_b);
	ft_putendl_fd("rrr", 1);
}
