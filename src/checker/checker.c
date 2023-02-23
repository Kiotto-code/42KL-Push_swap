/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:11:41 by yichan            #+#    #+#             */
/*   Updated: 2023/01/12 22:56:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	execute(char *line, t_list **stk_a, t_list **stk_b)
{
	if (!ft_strcmp(line, "ra\n"))
		ps_ra(stk_a);
	else if (!ft_strcmp(line, "rb\n"))
		ps_rb(stk_b);
	else if (!ft_strcmp(line, "rr\n"))
		ps_rr(stk_a, stk_b);
	else if (!ft_strcmp(line, "rra\n"))
		ps_rra(stk_a);
	else if (!ft_strcmp(line, "rrb\n"))
		ps_rrb(stk_b);
	else if (!ft_strcmp(line, "rrr\n"))
		ps_rrr(stk_a, stk_b);
	else if (!ft_strcmp(line, "pa\n"))
		ps_pa(stk_a, stk_b);
	else if (!ft_strcmp(line, "pb\n"))
		ps_pb(stk_a, stk_b);
	else if (!ft_strcmp(line, "sa\n"))
		ps_sa(stk_a);
	else if (!ft_strcmp(line, "sb\n"))
		ps_sb(stk_b);
	else if (!ft_strcmp(line, "ss\n"))
		ps_ss(stk_a, stk_b);
	else
		ft_error("Error");
}

void	get_op(t_list **stk_a, t_list *stk_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (line)
		{
			execute(line, stk_a, &stk_b);
			free(line);
		}
	}
	if (!(ft_lstsize(stk_b)) && !stk_xsorted(*stk_a))
		ft_putendl_fd("OK", 1);
	else
	{
		ft_stkclear(&stk_b, &destroy);
		ft_putendl_fd("KO", 1);
	}
}

void	check_lstdup(t_list *stk_a)
{
	t_list	*temp;

	if (!stk_a)
		return ;
	temp = stk_a;
	while (temp)
	{
		stk_a = temp->next;
		while (stk_a)
		{
			if (stk_a->content->nbr == temp->content->nbr)
			{
				free (stk_a);
				write (1, "Error\n", ft_strlen("Error\n"));
				exit(EXIT_FAILURE);
			}
			stk_a = stk_a->next;
		}
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stk_a;
	t_list	*stk_b;

	if (ac == 1)
		return (0);
	inputcheck(av);
	stk_a = get_av(ac, av);
	check_lstdup(stk_a);
	stk_b = NULL;
	get_op(&stk_a, stk_b);
	ft_stkclear(&stk_a, &destroy);
	ft_stkclear(&stk_b, &destroy);
	return (0);
}
