/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:18:05 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:54:12 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_list **stk)
{
	t_list	*temp;
	t_list	*last;

	temp = (*stk);
	(*stk) = (*stk)->next;
	last = ft_lstlast(temp);
	last->next = temp;
	temp->next = NULL;
}

void	ps_ra(t_list **stk_a)
{
	ps_rotate(stk_a);
	ft_putendl_fd("ra", 1);
}

void	ps_rb(t_list **stk_b)
{
	ps_rotate(stk_b);
	ft_putendl_fd("rb", 1);
}

void	ps_rr(t_list **stk_a, t_list **stk_b)
{
	ps_rotate(stk_a);
	ps_rotate(stk_b);
	ft_putendl_fd("rr", 1);
}
