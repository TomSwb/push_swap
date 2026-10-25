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
