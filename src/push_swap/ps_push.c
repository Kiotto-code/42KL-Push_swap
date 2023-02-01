/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:50:19 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:26:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ps_push(t_list **src, t_list **dest)
// {
// 	t_list	*temp;

// 	if (!(*src))
// 		return ;
// 	temp = (*src)->next;
// 	(*src)->next = *dest;
// 	*dest = *src;
// 	*src = temp;
// }

static void	ps_push(t_list **dest, t_list **src)
{
	t_list	*temp;

	if (!(*src))
		return ;
	temp = *src;
	(*src) = (*src)->next;
	ft_lstadd_front(dest, temp);
}

void	ps_pa(t_list **stk_a, t_list **stk_b)
{
	ps_push(stk_a, stk_b);
	ft_putendl_fd("pa", 1);
}

void	ps_pb(t_list **stk_a, t_list **stk_b)
{
	ps_push(stk_b, stk_a);
	ft_putendl_fd("pb", 1);
}
