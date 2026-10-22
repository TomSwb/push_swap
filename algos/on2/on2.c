/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:28:41 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 16:19:32 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

void	cost_based_insertion(t_stack *stack_a, t_stack *stack_b)
{
	while (3 < stack_a->size)
		pb(stack_a, stack_b);
	sort_first_three(stack_a, stack_b);
}


void	sort_first_three(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*max;

	max = find_max_node(stack_a);
	if (stack_a->top == max ||  stack_a->top->prev == max)
	{
		if (stack_a->top == max)
			ra(stack_a, stack_b, 0);
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a, stack_b, 0);
	}
	else if (stack_a->top->next == max)
	{
		if (stack_a->top->value > stack_a->top->prev->value)
			rra(stack_a, stack_b, 0);
		else
		{
			sa(stack_a, stack_b, 0);
			ra(stack_a, stack_b, 0);
		}
	}
}
