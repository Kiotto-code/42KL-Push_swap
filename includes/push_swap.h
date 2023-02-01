/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:16:53 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:57:12 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_action
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
	int	action;
}	t_action;

t_list		*ft_list_new(char *str);
t_list		*ft_struct_new(char *str);
int			ft_atol(const char *str);
void		ft_stkclear(t_list **lst, void (*del)(t_stk *));
void		destroy(t_stk *item);
void		quicksort(int arr[], int low, int high);
void		checkmax(long n);
int			*arr_sort(t_list *stk_a);
void		ins_sort(t_list **stk_a, int *sorted, int sort_size);
void		check_dup(int *sorted, int size);
int			inputcheck(char **av);
int			get_index(t_list *stk);
int			get_maxb_index(t_list *stk);
int			get_pusheda_ind(t_list *stk_a, t_list *stk_b);
void		ps_greedy(t_list **stk_a, t_list **stk_b, t_action *cheapbook);

// ps_sort.c
void		ps_sort(t_list **stk_a, t_list **stk_b);

// action/operation
void		ps_revrotate(t_list **stk);
void		ps_rotate(t_list **stk);

void		ps_pb(t_list **stk_a, t_list **stk_b);
void		ps_pa(t_list **stk_a, t_list **stk_b);;
void		ps_rb(t_list **stk_b);
void		ps_ra(t_list **stk_a);
void		ps_rr(t_list **stk_a, t_list **stk_b);
void		ps_rra(t_list **stk_a);
void		ps_rrb(t_list **stk_b);
void		ps_rrr(t_list **stk_a, t_list **stk_b);
void		ps_sa(t_list **stk_a);
void		ps_sb(t_list **stk_b);
void		ps_ss(t_list **stk_a, t_list **stk_b);

/*ps_sorting_stacks.c*/
void		sorting_stacks(t_list **a_stk, t_list **b_stk);
int			stk_xsorted(t_list *stk);

// ps_action.c
void		ps_action1(t_list **stk_a, t_list **stk_b, t_action cheapbook);
void		ps_action2(t_list **stk_a, t_list **stk_b, t_action cheapbook);
void		ps_action3(t_list **stk_a, t_list **stk_b, t_action cheapbook);
void		ps_action4(t_list **stk_a, t_list **stk_b, t_action cheapbook);

#endif