/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:12:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 14:44:07 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

int	is_sort(t_stack *stack)
{
	size_t	i;
	t_value	*temp;

	i = 0;
	temp = stack->top;
	while (i < stack->size - 1)
	{
		if (temp->value > temp->next->value)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

void	init_cheapest(t_cheapest *cheapest)
{
	cheapest->a_moves = 0;
	cheapest->b_moves = 0;
	cheapest->cost = INT_MAX;
	cheapest->element = NULL;
}

int	count_hops(t_stack *stack, t_value *node)
{
	int		i;
	t_value	*temp;

	i = 0;
	temp = stack->top;
	while (temp != node)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
