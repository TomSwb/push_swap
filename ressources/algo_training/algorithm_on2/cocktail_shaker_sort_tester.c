/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocktail_shaker_sort_tester.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:55:32 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:42:04 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo_training.h"

void	test_css(int *arr, int len)
{
	int	i;
	int	comparisons;
	int	swaps;
	int	moves;

	comparisons = 0;
	swaps = 0;
	moves = 0;
	i = 0;
	ft_printf("\n");
	while (i < len - 1)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_printf("%d\n", arr[i]);
	cocktail_shaker_sort(arr, len, &comparisons, &swaps, &moves);
	i = 0;
	while (i < len - 1)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_printf("%d\n", arr[i]);
	ft_printf("Comparisons: %d\n", comparisons);
	ft_printf("Bubble Swaps: %d\n", swaps);
	ft_printf("Moves: %d\n", moves);
}
