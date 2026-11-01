/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:57:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:25:54 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Rotates stack_a up (first node becomes last): since the
list is circular, it just moves top to the next node.
Does nothing if stack_a is empty.
Prints "ra" and counts it only if rr_bool is 0 (when called
from rr, it moves silently). stack_b is unused, only there
so every move has the same parameters.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param int rr_bool
* @return void
*/
void	ra(t_stack *stack_a, t_stack *stack_b, int rr_bool)
{
	if (!stack_a->top)
		return ;
	(void) stack_b;
	stack_a->top = stack_a->top->next;
	if (rr_bool)
		return ;
	ft_printf("ra\n");
	(stack_a->moves.ra_moves)++;
}

/**
* @brief
Rotates stack_b up (first node becomes last): since the
list is circular, it just moves top to the next node.
Does nothing if stack_b is empty.
Prints "rb" and counts it only if rr_bool is 0 (when called
from rr, it moves silently). The count is stored in
stack_a, like every move counter.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param int rr_bool
* @return void
*/
void	rb(t_stack *stack_a, t_stack *stack_b, int rr_bool)
{
	if (!stack_b->top)
		return ;
	stack_b->top = stack_b->top->next;
	if (rr_bool)
		return ;
	ft_printf("rb\n");
	(stack_a->moves.rb_moves)++;
}

/**
* @brief
ra and rb at the same time: calls both silently, then
prints "rr" and counts it once.
Does nothing if either stack is empty.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
		return ;
	ra(stack_a, stack_b, 1);
	rb(stack_a, stack_b, 1);
	ft_printf("rr\n");
	(stack_a->moves.rr_moves)++;
}
