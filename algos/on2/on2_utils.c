/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:12:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 15:14:33 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

void	two_elements_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a, stack_b, 0);
	return ;
}

t_value	*find_max_node(t_stack *stack)
{
	size_t	i;
	t_value *temp;
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

int	is_sort(t_stack *stack)
{
	size_t	i;
	t_value *temp;

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