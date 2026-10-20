/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:57:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 16:28:38 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack_a, t_stack *stack_b, int rr_bool)
{
	if (!stack_a->top)
		return (0);
	(void) stack_b;
	stack_a->top = stack_a->top->next;
	if (rr_bool)
		return (1);
	ft_putendl_fd("ra", stack_a->fd);
	(stack_a->moves)++;
	return (1);
}

int	rb(t_stack *stack_a, t_stack *stack_b, int rr_bool)
{
	if (!stack_b->top)
		return (0);
	(void) stack_a;
	stack_b->top = stack_b->top->next;
	if (rr_bool)
		return (1);
	ft_putendl_fd("rb", stack_b->fd);
	(stack_b->moves)++;
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
		return (0);
	ra(stack_a, stack_b, 1);
	rb(stack_a, stack_b, 1);
	ft_putendl_fd("rr", stack_a->fd);
	(stack_a->moves)++;
	return (1);
}
