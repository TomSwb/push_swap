/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:46:46 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 14:32:53 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

void	find_cheapest(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	t_cheapest	current;
	size_t		i;
	t_value		*temp;

	i = 0;
	temp = stack_b->top;
	init_cheapest(&current);
	init_cheapest(cheapest);
	while (i < stack_b->size)
	{
		element_cost(stack_a, stack_b, &current, temp);
		if (current.cost < cheapest->cost)
			*cheapest = current;
		temp = temp->next;
		i++;
	}
}

void	element_cost(t_stack *stack_a, t_stack *stack_b, t_cheapest *current,
	t_value *b_node)
{
	t_value	*target_node;
	int		a_up;
	int		b_up;
	
	target_node = find_target_node(stack_a, b_node);
	a_up = count_hops(stack_a, target_node);
	b_up = count_hops(stack_b, b_node);
}
