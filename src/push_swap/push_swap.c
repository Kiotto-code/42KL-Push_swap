/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:09:34 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:54:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(t_list **stk_a, t_list *stk_b, int size)
{
	int		*sorted;

	sorted = arr_sort(*stk_a);
	check_dup(sorted, size);
	ins_sort(stk_a, sorted, size);
	sorting_stacks(stk_a, &stk_b);
	free (sorted);
	ft_stkclear(&stk_b, &destroy);
}

int	main(int ac, char**av)
{
	t_list	*stk_a;
	t_list	*stk_b;
	int		size;

	if (ac == 1)
		return (0);
	inputcheck(av);
	stk_a = get_av(ac, av);
	size = ft_lstsize(stk_a);
	stk_b = NULL;
	push_swap(&stk_a, stk_b, size);
	ft_stkclear(&stk_b, &destroy);
	return (0);
}
