/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:12:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 13:48:11 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

t_value	*find_max_node(t_stack *stack)
{
	size_t	i;
	t_value	*temp;
	int		max;
	t_value	*max_node;

	if (stack->top == NULL)
		return (NULL);
	i = 0;
	temp = stack->top;
	max_node = temp;
	max = temp->value;
	temp = temp->next;
	while (i < stack->size - 1)
	{
		if (max < temp->value)
		{
			max_node = temp;
			max = temp->value;
		}
		i++;
		temp = temp->next;
	}
	return (max_node);
}

t_value	*find_min_node(t_stack *stack)
{
	size_t	i;
	t_value	*temp;
	int		min;
	t_value	*min_node;

	if (stack->top == NULL)
		return (NULL);
	i = 0;
	temp = stack->top;
	min_node = temp;
	min = temp->value;
	temp = temp->next;
	while (i < stack->size - 1)
	{
		if (min > temp->value)
		{
			min_node = temp;
			min = temp->value;
		}
		i++;
		temp = temp->next;
	}
	return (min_node);
}

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
	cheapest->a_r = 0;
	cheapest->a_rr = 0;
	cheapest->b_r = 0;
	cheapest->b_rr = 0;
	cheapest->cost = 0;
	cheapest->element = NULL;
}