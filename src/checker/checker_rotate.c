/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:29 by yichan            #+#    #+#             */
/*   Updated: 2023/01/12 22:56:28 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
}

void	ps_rb(t_list **stk_b)
{
	ps_rotate(stk_b);
}

void	ps_rr(t_list **stk_a, t_list **stk_b)
{
	ps_rotate(stk_a);
	ps_rotate(stk_b);
}
