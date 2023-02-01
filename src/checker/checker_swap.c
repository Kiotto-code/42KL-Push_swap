/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:15:36 by yichan            #+#    #+#             */
/*   Updated: 2023/01/12 22:56:31 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	swap(t_list *stack)
{
	void	*temp;

	if (!stack || !(stack->next))
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	ps_sa(t_list **stk_a)
{
	swap(*stk_a);
}

void	ps_sb(t_list **stk_b)
{
	swap(*stk_b);
}

void	ps_ss(t_list **stk_a, t_list **stk_b)
{
	swap(*stk_a);
	swap(*stk_b);
}
