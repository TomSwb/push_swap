/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_find_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:16:00 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 15:48:53 by tschwab          ###   ########.ch       */
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
	max = temp->rank;
	temp = temp->next;
	while (i < stack->size - 1)
	{
		if (max < temp->rank)
		{
			max_node = temp;
			max = temp->rank;
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
	min = temp->rank;
	temp = temp->next;
	while (i < stack->size - 1)
	{
		if (min > temp->rank)
		{
			min_node = temp;
			min = temp->rank;
		}
		i++;
		temp = temp->next;
	}
	return (min_node);
}

t_value	*find_target_node(t_stack *stack_a, t_value *b_node)
{
	size_t	i;
	t_value	*temp;
	t_value	*target_node;

	if (stack_a->top == NULL)
		return (NULL);
	i = 0;
	temp = stack_a->top;
	target_node = NULL;
	while (i < stack_a->size)
	{
		if (temp->rank > b_node->rank
			&& (target_node == NULL || temp->rank < target_node->rank))
			target_node = temp;
		i++;
		temp = temp->next;
	}
	if (target_node == NULL)
		return (find_min_node(stack_a));
	return (target_node);
}
