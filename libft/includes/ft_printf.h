/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:57:09 by yichan            #+#    #+#             */
/*   Updated: 2022/12/31 12:57:14 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

/*
	da	dash;
	ze	zero;
	dt	dot;
	ha	hash;
	sp	space;
	pl	plus;
	wi	width;
	pr	precision;
	sr	specifier;
*/
typedef struct s_flags
{
	int		da;
	int		ze;
	int		dt;
	int		ha;
	int		sp;
	int		pl;
	int		wi;
	int		pr;
	char	sr;
}	t_flags;

t_flags	*ftpf_get_flags(char *string, int *i);

int		ftpf_char(char c, t_flags *flags);
int		ftpf_str(char *s, t_flags *flags);
int		ftpf_int(long n, t_flags *flags);
int		ftpf_hex(unsigned long n, t_flags *flags, char *base, int ptr);

int		ftpf_width(int width, char c);
void	ftpf_get_neg(long *n, int *neg);
int		ftpf_max(int a, int b);
int		ftpf_get_len_base(unsigned long n, int base_len);
void	ftpf_print_base(unsigned long n, char *base);

int		ftpf_print_args(va_list args, t_flags *flags);
int		ft_printf(const char *format, ...);

#endif