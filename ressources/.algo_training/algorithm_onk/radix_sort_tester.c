/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:13:49 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:43:53 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo_training.h"

void	test_radix(int *arr, int len)
{
	int	i;
	// int selections;
	// int comparisons;
	// selections = 0;
	// comparisons = 0;
	i = 0;
	while (i < len - 1)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_printf("%d\n", arr[i]);
	radix_sort(arr, len);
	i = 0;
	while (i < len - 1)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_printf("%d\n", arr[i]);
	// ft_printf("Comparisons: %d\n", comparisons);
	// ft_printf("Selections: %d\n", selections);
	// ft_printf("Moves: %d\n", selections);
}
