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

void	rrb(t_stack *stack_a, t_stack *stack_b, int rrr_bool)
{
	if (!stack_b->top)
		return ;
	(void) stack_a;
	stack_b->top = stack_b->top->prev;
	if (rrr_bool)
		return ;
	ft_printf("rrb\n");
	(stack_a->moves.rrb_moves)++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
		return ;
	rra(stack_a, stack_b, 1);
	rrb(stack_a, stack_b, 1);
	ft_printf("rrr\n");
	(stack_a->moves.rrr_moves)++;
}
