/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:21:07 by marvin            #+#    #+#             */
/*   Updated: 2023/01/13 00:21:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
