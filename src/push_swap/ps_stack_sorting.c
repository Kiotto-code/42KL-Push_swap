/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:48:57 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:48:41 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_xsorted(t_list *stk)
{
	if (!stk)
		ft_error("Error: Nothing to sort");
	while (stk->next)
	{
		if (get_index(stk) > get_index(stk->next))
			return (1);
		stk = stk->next;
	}
	return (0);
}

void	all_sorted(t_list *stk_a, t_list *stk_b)
{
	if (!stk_a)
		ft_error("Error: Nothing to sort");
	if (!(ft_lstsize(stk_b)) && !stk_xsorted(stk_a))
	{
		exit(EXIT_SUCCESS);
	}
}

void	initial3_sort(t_list **stk)
{
	int	max_index;

	if (ft_lstsize(*stk) == 2 && get_index(*stk) > (get_index((*stk)->next)))
		ps_sa(stk);
	else
	{
		max_index = get_maxb_index(*stk);
		if (max_index == 0)
			ps_ra(stk);
		else if (max_index == 1)
			ps_rra(stk);
		if (get_index(*stk) > get_index((*stk)->next))
			ps_sa(stk);
	}
}

void	sorting_stacks(t_list **stk_a, t_list **stk_b)
{
	int		lst_len;
	int		med_value;

	(void)stk_b;
	if (stk_xsorted(*stk_a) == 0)
		exit (EXIT_SUCCESS);
	lst_len = ft_lstsize(*stk_a);
	med_value = lst_len / 2;
	while (lst_len > 3)
	{
		if (med_value < get_index(*stk_a) && lst_len
			> med_value && med_value > 100)
			ps_ra(stk_a);
		else
		{
			ps_pb(stk_a, stk_b);
			lst_len--;
		}
	}
	initial3_sort(stk_a);
	all_sorted(*stk_a, *stk_b);
	ps_sort(stk_a, stk_b);
}
