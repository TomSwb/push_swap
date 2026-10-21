/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:35:59 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/21 10:51:21 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack_a, t_stack *stack_b, int rrr_bool)
{
	if (!stack_a->top)
	{
	// TO SUPPRESS BEFORE FINAL PUSH
		if (!rrr_bool)
			ft_printf("useless rra move\n");
	// TO SUPPRESS BEFORE FINAL PUSH
		return ;
	}
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
	{
	// TO SUPPRESS BEFORE FINAL PUSH
		if (!rrr_bool)
			ft_printf("useless rrb move\n");
	// TO SUPPRESS BEFORE FINAL PUSH
		return ;
	}
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
	{
	// TO SUPPRESS BEFORE FINAL PUSH
		ft_printf("useless rrr move\n");
	// TO SUPPRESS BEFORE FINAL PUSH
		return ;
	}
	rra(stack_a, stack_b, 1);
	rrb(stack_a, stack_b, 1);
	ft_putendl_fd("rrr", stack_a->fd);
	(stack_a->moves)++;
}
