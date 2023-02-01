/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:19:40 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 21:47:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_list	*get_av(int ac, char **av)
{
	char	**arr;
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	temp = 0;
	while (++i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!av[i])
			ft_error("Error: nothing to split");
		j = 0;
		while (arr[j])
		{
			ft_lstadd_back(&temp, ft_lstnew(ft_lstnew2(ft_atol(arr[j]))));
			free(arr[j]);
			arr[j++] = 0;
		}
		free(arr);
		arr = 0;
	}
	return (temp);
}

int	get_index(t_list *stk)
{
	return (stk->content->nbr);
}
