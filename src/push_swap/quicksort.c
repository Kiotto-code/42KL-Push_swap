/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:28:48 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:56:21 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int array[], int low, int high)
{
	int	pivot;
	int	j;

	pivot = array[high];
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
			swap(&array[low++], &array[j]);
		j++;
	}
	swap(&array[low], &array[high]);
	return (low);
}

void	quicksort(int arr[], int low, int high)
{
	int	piv;

	if (low < high)
	{
		piv = partition(arr, low, high);
		quicksort(arr, low, piv -1);
		quicksort(arr, piv +1, high);
	}
}
