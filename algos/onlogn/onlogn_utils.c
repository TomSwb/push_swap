/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:38:44 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/25 17:02:44 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

t_chunk	new_chunk(t_loc loc, int min, int max)
{
	t_chunk	chunk;

	chunk.loc = loc;
	chunk.loc_small = NO_LOC;
	chunk.loc_medium = NO_LOC;
	chunk.loc_big = NO_LOC;
	chunk.min = min;
	chunk.max = max;
	chunk.pivot_low = -1;
	chunk.pivot_high = -1;
	chunk.size = chunk.max - chunk.min + 1;
	return (chunk);
}

void	move_to_top_a(t_stack *stack_a, t_stack *stack_b, t_loc loc)
{
	if (loc == BOT_A)
		rra(stack_a, stack_b, 0);
	else if (loc == BOT_B)
		rrb(stack_a, stack_b, 0);
	if (loc == TOP_B || loc == BOT_B)
		pa(stack_a, stack_b, 0);
}

void	two_elements_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->rank > stack_a->top->next->rank)
		sa(stack_a, stack_b, 0);
	return ;
}

void	sort_top_three(t_stack *stack_a, t_stack *stack_b)
{
	two_elements_sort(stack_a, stack_b);
	if (stack_a->top->next->rank > stack_a->top->next->next->rank)
	{
		ra(stack_a, stack_b, 0);
		sa(stack_a, stack_b, 0);
		rra(stack_a, stack_b, 0);
	}
	two_elements_sort(stack_a, stack_b);
}
