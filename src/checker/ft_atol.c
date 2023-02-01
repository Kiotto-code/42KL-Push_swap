/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:17:10 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:21:37 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_atol(const char *str)
{
	long		result;
	long		sign;
	long		ret;

	result = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	if (!ft_isdigit(*str))
		ft_error("Error");
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str++ - '0');
	}
	if (*str)
		ft_error("Error");
	ret = (sign * result);
	checkmax(ret);
	return (ret);
}
