/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:04:47 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 16:21:19 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putendl_fd("sa", 1);
}

void	ps_sb(t_list **stk_b)
{
	swap(*stk_b);
	ft_putendl_fd("sb", 1);
}

void	ps_ss(t_list **stk_a, t_list **stk_b)
{
	swap(*stk_a);
	swap(*stk_b);
	ft_putendl_fd("ss", 1);
}
