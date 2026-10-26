/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:57:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 18:00:45 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack_a, t_stack *stack_b, int rr_bool)
{
	if (!stack_a->top)
	{
		// TO SUPPRESS BEFORE FINAL PUSH
		if (!rr_bool)
			ft_printf("useless ra move\n");
		// TO SUPPRESS BEFORE FINAL PUSH
		return ;
	}
	(void) stack_b;
	stack_a->top = stack_a->top->next;
	if (rr_bool)
		return ;
	ft_printf("ra\n");
	(stack_a->moves.ra_moves)++;
}

void	rb(t_stack *stack_a, t_stack *stack_b, int rr_bool)
{
	if (!stack_b->top)
	{
	// TO SUPPRESS BEFORE FINAL PUSH
		if (!rr_bool)
			ft_printf("useless rb move\n");
	// TO SUPPRESS BEFORE FINAL PUSH
		return ;
	}
	(void) stack_a;
	stack_b->top = stack_b->top->next;
	if (rr_bool)
		return ;
	ft_printf("rb\n");
	(stack_a->moves.rb_moves)++;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->top || !stack_b->top)
	{
	// TO SUPPRESS BEFORE FINAL PUSH
		ft_printf("useless rr move\n");
	// TO SUPPRESS BEFORE FINAL PUSH
		return ;
	}
	ra(stack_a, stack_b, 1);
	rb(stack_a, stack_b, 1);
	ft_printf("rr\n");
	(stack_a->moves.rr_moves)++;
}
