/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_revrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:13:30 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 23:37:34 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
}

void	ps_rrb(t_list **stk_b)
{
	ps_revrotate(stk_b);
}

void	ps_rrr(t_list **stk_a, t_list **stk_b)
{
	ps_revrotate(stk_a);
	ps_revrotate(stk_b);
}
