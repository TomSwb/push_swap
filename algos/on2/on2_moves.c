/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:58:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:24:43 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Rotates both stacks so cheapest->element is on top of stack_b and
its target on top of stack_a, then pushes it onto stack_a.
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
	pa(stack_a, stack_b, 0);
}

/**
* @brief
Rotates both stacks at once while a_moves and b_moves go the same
way: rr while both are positive, rrr while both are negative.
Updates the counts, leaving the rest for move_a and move_b.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_cheapest *cheapest
* @return void
*/
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

/**
* @brief
Rotates stack_a by the remaining a_moves: ra while it's positive,
rra while it's negative, until a_moves reaches 0.
stack_b is only passed through to the moves.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_cheapest *cheapest
* @return void
*/
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

/**
* @brief
Rotates stack_b by the remaining b_moves: rb while it's positive,
rrb while it's negative, until b_moves reaches 0.
stack_a is only passed through to the moves.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_cheapest *cheapest
* @return void
*/
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
