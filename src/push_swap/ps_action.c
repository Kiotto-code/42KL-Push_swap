/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:21 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:25:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_action1(t_list **stk_a, t_list **stk_b, t_action cheapbook)
{
	while (cheapbook.ra && cheapbook.rb)
	{
		ps_rr(stk_a, stk_b);
		cheapbook.ra--;
		cheapbook.rb--;
	}
	while (cheapbook.ra)
	{
		ps_ra(stk_a);
		cheapbook.ra--;
	}
	while (cheapbook.rb)
	{
		ps_rb(stk_b);
		cheapbook.rb--;
	}
}

void	ps_action2(t_list **stk_a, t_list **stk_b, t_action cheapbook)
{
	while (cheapbook.rra && cheapbook.rrb)
	{
		ps_rrr(stk_a, stk_b);
		cheapbook.rra--;
		cheapbook.rrb--;
	}
	while (cheapbook.rra)
	{
		ps_rra(stk_a);
		cheapbook.rra--;
	}
	while (cheapbook.rrb)
	{
		ps_rrb(stk_b);
		cheapbook.rrb--;
	}
}

void	ps_action3(t_list **stk_a, t_list **stk_b, t_action cheapbook)
{
	while (cheapbook.ra)
	{
		ps_ra(stk_a);
		cheapbook.ra--;
	}
	while (cheapbook.rrb)
	{
		ps_rrb(stk_b);
		cheapbook.rrb--;
	}
}

void	ps_action4(t_list **stk_a, t_list **stk_b, t_action cheapbook)
{
	while (cheapbook.rra)
	{
		ps_rra(stk_a);
		cheapbook.rra--;
	}
	while (cheapbook.rb)
	{
		ps_rb(stk_b);
		cheapbook.rb--;
	}
}
