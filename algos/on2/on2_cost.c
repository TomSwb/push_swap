/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:46:46 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 13:54:03 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

void	find_cheapest(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	size_t	i;
	t_value	*temp;
	int		cost;

	cost = -1;
	i = 0;
	temp = stack_b->top;
	while (i < stack_b->size)
	{
		cost = element_cost(stack_a, stack_b, cheapest, temp);
		if (cheapest->cost > cost)
			cheapest->element = temp;
		temp = temp->next;
		i++;
	}
}

int	element_cost(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest, t_value *value)
{
	int		cost;
	t_value	*temp;

	cost = -1;
	temp = stack_b->top;
	return (cost);
}
