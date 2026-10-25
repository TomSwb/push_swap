/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:41:47 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/25 17:32:11 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

void	quick_sort_partitioning(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	first;

	first = new_chunk(TOP_A, 0, (int)stack_a->size - 1);
	sort_chunk(stack_a, stack_b, first);
}

void	sort_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	if (chunk.loc == BOT_A && (int)stack_a->size == chunk.size)
		chunk.loc = TOP_A;
	if (chunk.loc == BOT_B && (int)stack_b->size == chunk.size)
		chunk.loc = TOP_B;
	if (chunk.size <= 3)
	{
		sort_small_chunk(stack_a, stack_b, chunk);
		return ;
	}
	chunk.pivot_low = chunk.min + chunk.size / 3;
	chunk.pivot_high = chunk.min + chunk.size * 2 / 3;
	split_chunk(stack_a, stack_b, &chunk);
	sort_chunk(stack_a, stack_b, new_chunk(chunk.loc_big,
			chunk.pivot_high, chunk.max));
	sort_chunk(stack_a, stack_b, new_chunk(chunk.loc_medium,
			chunk.pivot_low, chunk.pivot_high - 1));
	sort_chunk(stack_a, stack_b, new_chunk(chunk.loc_small,
			chunk.min, chunk.pivot_low - 1));
}
