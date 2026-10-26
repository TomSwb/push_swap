/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:41:47 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 14:57:11 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

/**
* @brief
Sorts stack_a in ascending order with a three-way quicksort:
builds the first chunk covering the whole of stack_a
(ranks 0 to size - 1, on top of A) and hands it to sort_chunk,
which recurses.
Requires ranks normalized to 0..n-1 and stack_b empty.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	quick_sort_partitioning(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	first;

	first = new_chunk(TOP_A, 0, (int)stack_a->size - 1);
	sort_chunk(stack_a, stack_b, first);
}

/**
* @brief
Recursively sorts a chunk with a three-way partition.

If the chunk is alone in its stack, relabels BOT_A/BOT_B as
TOP_A/TOP_B (bottom and top are then the same nodes).

Chunks of 3 nodes or less are sorted directly: with
sort_first_three if exactly 3 nodes are alone in stack_a
(rotations are then free to use), otherwise with sort_small_chunk.

Otherwise sets the pivots at one and two thirds of the chunk's rank
range, splits it with split_chunk, then recurses on the big, middle
and small parts, in that order.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk chunk
* @return void
*/
void	sort_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	if (chunk.loc == BOT_A && (int)stack_a->size == chunk.size)
		chunk.loc = TOP_A;
	if (chunk.loc == BOT_B && (int)stack_b->size == chunk.size)
		chunk.loc = TOP_B;
	if (chunk.size <= 3)
	{
		if (chunk.loc == TOP_A && (int)stack_a->size == chunk.size
			&& chunk.size == 3)
			sort_first_three(stack_a, stack_b);
		else
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
