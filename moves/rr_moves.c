/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:35:59 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:25:58 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Reverse rotates stack_a (last node becomes first): since
the list is circular, it just moves top to the previous node.
Does nothing if stack_a is empty.
Prints "rra" and counts it only if rrr_bool is 0 (when
called from rrr, it moves silently). stack_b is unused,
only there so every move has the same parameters.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param int rrr_bool
* @return void
*/
void	rra(t_stack *stack_a, t_stack *stack_b, int rrr_bool)
{
	if (!stack_a->top)
		return ;
	(void) stack_b;
	stack_a->top = stack_a->top->prev;
	if (rrr_bool)
		return ;
	ft_printf("rra\n");
	(stack_a->moves.rra_moves)++;
}

/**
* @brief
Reverse rotates stack_b (last node becomes first): since
the list is circular, it just moves top to the previous node.
Does nothing if stack_b is empty.
Prints "rrb" and counts it only if rrr_bool is 0 (when
called from rrr, it moves silently). The count is stored
in stack_a, like every move counter.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param int rrr_bool
* @return void
*/
void	rrb(t_stack *stack_a, t_stack *stack_b, int rrr_bool)
{
	if (!stack_b->top)
		return ;
	stack_b->top = stack_b->top->prev;
	if (rrr_bool)
		return ;
	ft_printf("rrb\n");
	(stack_a->moves.rrb_moves)++;
}

/**
* @brief
rra and rrb at the same time: calls both silently, then
prints "rrr" and counts it once.
Does nothing if either stack is empty.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
		return ;
	rra(stack_a, stack_b, 1);
	rrb(stack_a, stack_b, 1);
	ft_printf("rrr\n");
	(stack_a->moves.rrr_moves)++;
}
