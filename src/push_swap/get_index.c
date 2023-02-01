/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:38:05 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:46:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *stk)
{
	return (stk->content->index);
}

int	get_maxb_index(t_list *stk)
{
	int	largest;
	int	position;
	int	i;

	position = 0;
	i = 1;
	largest = get_index(stk);
	stk = stk->next;
	while (stk)
	{
		if (get_index(stk) > largest)
		{
			largest = get_index(stk);
			position = i;
		}
		stk = stk->next;
		i ++;
	}
	return (position);
}

int	get_pusheda_ind(t_list *stk_a, t_list *stk_b)
{
	int	pushed;
	int	pushed_i;
	int	i;

	pushed = get_index(stk_a);
	pushed_i = 0;
	stk_a = stk_a->next;
	i = 1;
	while (stk_a)
	{
		if ((pushed > get_index(stk_a) && pushed < get_index(stk_b)) \
		|| (get_index(stk_a) > get_index(stk_b) && (pushed < get_index(stk_b) \
		|| pushed > get_index(stk_a))))
		{
			pushed = get_index(stk_a);
			pushed_i = i;
		}
		i++;
		stk_a = stk_a->next;
	}
	return (pushed_i);
}
