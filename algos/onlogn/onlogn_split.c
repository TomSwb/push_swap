/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 13:29:32 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/25 13:52:50 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

/**
* @brief
Splits a chunk into three parts (small, middle, big) around its
two pivots, by calling the split helper matching chunk->loc,
i.e. where the chunk currently sits (top or bottom of A or B).

The helper writes where each part ended up into chunk->loc_small,
loc_medium and loc_big, for sort_chunk to recurse on.

Requires the pivots to be set.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk *chunk
* @return void
*/
void	split_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	if (chunk->loc == TOP_A)
		split_top_a(stack_a, stack_b, chunk);
	else if (chunk->loc == BOT_A)
		split_bot_a(stack_a, stack_b, chunk);
	else if (chunk->loc == TOP_B)
		split_top_b(stack_a, stack_b, chunk);
	else if (chunk->loc == BOT_B)
		split_bot_b(stack_a, stack_b, chunk);
}

/**
* @brief
Splits a chunk sitting on top of stack_a, node by node:
ranks below pivot_low go to the bottom of stack_b,
ranks from pivot_low to below pivot_high go to the top of stack_b,
ranks from pivot_high up go to the bottom of stack_a.
Records those locations in chunk->loc_small, loc_medium, loc_big.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk *chunk
* @return void
*/
void	split_top_a(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->size)
	{
		if (stack_a->top->rank < chunk->pivot_low)
		{
			pb(stack_a, stack_b);
			rb(stack_a, stack_b, 0);
		}
		else if (stack_a->top->rank < chunk->pivot_high)
			pb(stack_a, stack_b);
		else
			ra(stack_a, stack_b, 0);
		i++;
	}
	chunk->loc_small = BOT_B;
	chunk->loc_medium = TOP_B;
	chunk->loc_big = BOT_A;
}

/**
* @brief
Splits a chunk sitting at the bottom of stack_a, bringing each node
up with rra first:
ranks below pivot_low go to the bottom of stack_b,
ranks from pivot_low to below pivot_high go to the top of stack_b,
ranks from pivot_high up stay on top of stack_a.
Records those locations in chunk->loc_small, loc_medium, loc_big.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk *chunk
* @return void
*/
void	split_bot_a(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->size)
	{
		rra(stack_a, stack_b, 0);
		if (stack_a->top->rank < chunk->pivot_low)
		{
			pb(stack_a, stack_b);
			rb(stack_a, stack_b, 0);
		}
		else if (stack_a->top->rank < chunk->pivot_high)
			pb(stack_a, stack_b);
		i++;
	}
	chunk->loc_small = BOT_B;
	chunk->loc_medium = TOP_B;
	chunk->loc_big = TOP_A;
}

/**
* @brief
Splits a chunk sitting on top of stack_b, node by node:
ranks below pivot_low go to the bottom of stack_b,
ranks from pivot_low to below pivot_high go to the bottom of stack_a,
ranks from pivot_high up go to the top of stack_a.
Records those locations in chunk->loc_small, loc_medium, loc_big.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk *chunk
* @return void
*/
void	split_top_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->size)
	{
		if (stack_b->top->rank < chunk->pivot_low)
			rb(stack_a, stack_b, 0);
		else if (stack_b->top->rank < chunk->pivot_high)
		{
			pa(stack_a, stack_b, 0);
			ra(stack_a, stack_b, 0);
		}
		else
			pa(stack_a, stack_b, 0);
		i++;
	}
	chunk->loc_small = BOT_B;
	chunk->loc_medium = BOT_A;
	chunk->loc_big = TOP_A;
}

/**
* @brief
Splits a chunk sitting at the bottom of stack_b, bringing each node
up with rrb first:
ranks below pivot_low stay on top of stack_b,
ranks from pivot_low to below pivot_high go to the bottom of stack_a,
ranks from pivot_high up go to the top of stack_a.
Records those locations in chunk->loc_small, loc_medium, loc_big.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk *chunk
* @return void
*/
void	split_bot_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->size)
	{
		rrb(stack_a, stack_b, 0);
		if (stack_b->top->rank >= chunk->pivot_high)
			pa(stack_a, stack_b, 0);
		else if (stack_b->top->rank >= chunk->pivot_low)
		{
			pa(stack_a, stack_b, 0);
			ra(stack_a, stack_b, 0);
		}
		i++;
	}
	chunk->loc_small = TOP_B;
	chunk->loc_medium = BOT_A;
	chunk->loc_big = TOP_A;
}
