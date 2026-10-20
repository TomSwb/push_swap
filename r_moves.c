/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:57:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 15:38:31 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(void) stack_b;

	(stack_a->moves)++;
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(void) stack_a;
	
	(stack_b->moves)++;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	
	
	(stack_a->moves)++;
}
