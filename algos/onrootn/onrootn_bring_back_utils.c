/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_bring_back_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:10:17 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/02 01:31:18 by tschwab          ###   ########.ch       */
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
	int	max;

	max = s_b->size - 1;
	bring_to_top(s_a, s_b, find_pos(s_b, max - 1));
	pa(s_a, s_b, 0);
	bring_to_top(s_a, s_b, find_pos(s_b, max));
	pa(s_a, s_b, 0);
	sa(s_a, s_b, 0);
}
