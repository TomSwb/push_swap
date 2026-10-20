/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:35:59 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 16:01:18 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(void) stack_b;

	ft_printf("rra\n");
	(stack_a->moves)++;
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(void) stack_a;
	ft_printf("rrb\n");
	(stack_b->moves)++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	
	ft_printf("rrr\n");	
	(stack_a->moves)++;
}