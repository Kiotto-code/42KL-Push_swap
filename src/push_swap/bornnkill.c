/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bornnkill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:43:17 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:23:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy(t_stk *item)
{
	free(item);
	item = 0;
}

void	ft_stkdelone(t_list *lst, void (*del)(t_stk *))
{
	t_stk	*temp;

	if (!lst || !del)
		return ;
	temp = lst->content;
	del(temp);
	temp = 0;
}

void	ft_stkclear(t_list **lst, void (*del)(t_stk *))
{
	t_list	*temp;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_stkdelone(temp, del);
		free(temp);
	}
	temp = 0;
	*lst = NULL;
}
