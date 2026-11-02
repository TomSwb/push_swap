/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_bring_back_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:10:17 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/02 01:21:09 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_pos(t_stack *stack, int rank)
{
	size_t	pos;
	t_value *temp;

	pos = 0;
	temp = stack->top;
	while (temp->rank != rank)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}

size_t	rot_cost(size_t pos, size_t size)
{
	if (size - pos < pos)
		return (size - pos);
	return (pos);
}

void	bring_to_top(t_stack *s_a, t_stack *s_b, size_t pos)
{
	size_t	i;

	if (pos <= s_b->size / 2)
	{
		while (pos > 0)
		{
			rb(s_a, s_b, 0);
			pos--;
		}
	}
	else 
	{
		i = s_b->size - pos;
		while (i > 0 )
		{
			rrb(s_a, s_b, 0);
			i--;
		}
	}
}

void	second_first(t_stack *s_a, t_stack *s_b)
{
	
}

t_value	*node_to_move(t_stack *stack_b, size_t *pos)
{
	size_t	sec_pos;
	t_value	*highest;
	t_value	*second_high;
	
	highest = stack_b->top;
	while(highest->rank != (int)stack_b->size - 1)
	{
		highest = highest->next;
		(*pos)++;
	}
	sec_pos = 0;
	second_high = stack_b->top;
	while(second_high->rank != (int)stack_b->size - 2)
	{
		second_high = second_high->next;
		sec_pos++;
	}
	if (*pos < sec_pos && )
		return (highest);
	*pos = sec_pos;
	return (second_high);
}