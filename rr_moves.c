/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:35:59 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 15:38:22 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(void) stack_b;

	(stack_a->moves)++;
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(void) stack_a;
	
	(stack_b->moves)++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(stack_a->moves)++;
}