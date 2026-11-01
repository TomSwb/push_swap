/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:15:02 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:52:05 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo_training.h"

void	quick_sort(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	temp;

	if (low >= high)
		return ;
	i = low + 1;
	j = low + 1;
	while (j <= high)
		quick_loop(arr, &i, &j, low);
	i--;
	temp = arr[low];
	arr[low] = arr[i];
	arr[i] = temp;
	quick_sort(arr, low, i - 1);
	quick_sort(arr, i + 1, high);
}

void	quick_loop(int *arr, int *i, int *j, int low)
{
	int	pivot;
	int	temp;

	pivot = arr[low];
	if (arr[*j] < pivot)
	{
		temp = arr[*j];
		arr[*j] = arr[*i];
		arr[*i] = temp;
		(*i)++;
	}
	(*j)++;
}
