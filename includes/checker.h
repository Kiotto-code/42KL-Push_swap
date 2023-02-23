/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:12:55 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 19:19:42 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

// check_utils.c
t_list	*get_av(int ac, char **av);
int		get_index(t_list *stk);

// checker_check.c
int		inputcheck(char **av);
void	check_dup(int sorted[], int size);
void	checkmax(long n);
int		stk_xsorted(t_list *stk);
void	all_sorted(t_list *stk_a, t_list *stk_b);

void	ps_rra(t_list **stk_a);
void	ps_rrb(t_list **stk_b);
void	ps_rrr(t_list **stk_a, t_list **stk_b);
void	ps_pa(t_list **stk_a, t_list **stk_b);
void	ps_pb(t_list **stk_a, t_list **stk_b);
void	ps_rr(t_list **stk_a, t_list **stk_b);
void	ps_ra(t_list **stk_a);
void	ps_rb(t_list **stk_b);
void	ps_sa(t_list **stk_a);
void	ps_sb(t_list **stk_b);
void	ps_ss(t_list **stk_a, t_list **stk_b);
int		ft_atol(const char *str);

// checker_kill.c
void	destroy(t_stk *item);
void	ft_stkdelone(t_list *lst, void (*del)(t_stk *));
void	ft_stkclear(t_list **lst, void (*del)(t_stk *));

#endif