/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:58:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 15:05:21 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

/**
* @brief
Rotates both stacks so cheapest->element is on top of stack_b and
its target on top of stack_a, ready for pa (the push isn't done here).
Shared moves first (rr / rrr), then what's left on each stack.
Consumes cheapest's a_moves and b_moves (both end at 0).

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_cheapest *cheapest
* @return void
*/
void	move_cheapest_node(t_stack *stack_a, t_stack *stack_b,
		t_cheapest *cheapest)
{
	move_together(stack_a, stack_b, cheapest);
	move_a(stack_a, stack_b, cheapest);
	move_b(stack_a, stack_b, cheapest);
}

void	move_together(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	while (cheapest->a_moves > 0 && cheapest->b_moves > 0)
	{
		rr(stack_a, stack_b);
		cheapest->a_moves--;
		cheapest->b_moves--;
	}
	while (cheapest->a_moves < 0 && cheapest->b_moves < 0)
	{
		rrr(stack_a, stack_b);
		cheapest->a_moves++;
		cheapest->b_moves++;
	}
}

void	move_a(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	while (cheapest->a_moves > 0)
	{
		ra(stack_a, stack_b, 0);
		cheapest->a_moves--;
	}
	while (cheapest->a_moves < 0)
	{
		rra(stack_a, stack_b, 0);
		cheapest->a_moves++;
	}
}

void	move_b(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	while (cheapest->b_moves > 0)
	{
		rb(stack_a, stack_b, 0);
		cheapest->b_moves--;
	}
	while (cheapest->b_moves < 0)
	{
		rrb(stack_a, stack_b, 0);
		cheapest->b_moves++;
	}
}
