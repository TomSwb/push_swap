/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:12:19 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/08 14:12:52 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo_training.h"

void	shell_sort(int *arr, int len)
{
	int	i;
	int	gap;
	int	swapped;
	int	swap_1;

	i = 0;
	swap_1 = 0;
	gap = len / 2;
	while (i < len - 1)
	{
		swapped = 0;
		while ((i + gap) < len)
			swapped += shell_manager(arr, &i, gap, &swap_1);
		if (gap / 2 > 1)
			gap /= 2;
		else
			gap = 1;
		if (swapped || !swap_1)
			i = 0;
		else
			i++;
	}
}

int	shell_manager(int *arr, int *i, int gap, int *swap_1)
{
	int	swapped;

	swapped = 0;
	if (gap == 1)
		(*swap_1) += 1;
	if (arr[*i] > arr[(*i) + gap])
		swapped += place_back_loop(arr, i, gap);
	else
		(*i)++;
	return (swapped);
}

int	place_back_loop(int *arr, int *i, int gap)
{
	int	temp;
	int	swapped;

	swapped = 0;
	while (*i >= 0 && arr[*i] > arr[(*i) + gap])
	{
		temp = arr[*i];
		arr[*i] = arr[(*i) + gap];
		arr[(*i) + gap] = temp;
		*i -= gap;
		swapped += 1;
	}
	*i = 0;
	return (swapped);
}
