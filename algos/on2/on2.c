/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:28:41 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 15:49:08 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

void	cost_based_insertion(t_stack *stack_a, t_stack *stack_b)
{
	t_cheapest	cheapest;
	int			min_hops;

	while (3 < stack_a->size)
		pb(stack_a, stack_b);
	sort_first_three(stack_a, stack_b);
	while (stack_b->top != NULL)
	{
		find_cheapest(stack_a, stack_b, &cheapest);
		move_cheapest_node(stack_a, stack_b, &cheapest);
		pa(stack_a, stack_b, 0);
	}
	min_hops = count_hops(stack_a, find_min_node(stack_a));
	while (stack_a->top->rank != 0)
	{
		if (min_hops <= (int)stack_a->size / 2)
			ra(stack_a, stack_b, 0);
		else
			rra(stack_a, stack_b, 0);
	}
}

void	sort_first_three(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*max;

	max = find_max_node(stack_a);
	if (stack_a->top == max)
		ra(stack_a, stack_b, 0);
	else if (stack_a->top->next == max)
		rra(stack_a, stack_b, 0);
	if (stack_a->top->rank > stack_a->top->next->rank)
		sa(stack_a, stack_b, 0);
}

