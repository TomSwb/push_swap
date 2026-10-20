/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:35:59 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 16:39:01 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_stack *stack_b, int rrr_bool)
{
	if (!stack_a->top)
		return ;
	(void) stack_b;
	stack_a->top = stack_a->top->prev;
	if (rrr_bool)
		return ;
	ft_putendl_fd("rra", stack_a->fd);
	(stack_a->moves)++;
}

void	rrb(t_stack *stack_a, t_stack *stack_b, int rrr_bool)
{
	if (!stack_b->top)
		return ;
	(void) stack_a;
	stack_b->top = stack_b->top->prev;
	if (rrr_bool)
		return ;
	ft_putendl_fd("rrb", stack_b->fd);
	(stack_b->moves)++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
		return ;
	rra(stack_a, stack_b, 1);
	rrb(stack_a, stack_b, 1);
	ft_putendl_fd("rrr", stack_a->fd);
	(stack_a->moves)++;
}
