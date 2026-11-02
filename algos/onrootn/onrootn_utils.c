/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:11:18 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 17:12:34 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_stack *stack_a, t_sensor *data)
{
	int	tweaker;

	tweaker = find_nxt_root(stack_a->init_size) * 5 / 2;
	data->chunk_size = tweaker;
	data->limit = data->chunk_size;
	data->pushed = 0;
	data->half = data->chunk_size / 2;
	data->top_pos = 0;
	data->bottom_pos = 0;
	data->rb_pending = 0;
}

/*
GOAL : find the biggest i so that i * i is smaller or equal to "size",
	aka the square root of size rounded down.
Return value : i
*/
int	find_nxt_root(int size)
{
	int	i;

	i = 1;
	while (i * i <= size)
		i++;
	return (i - 1);
}

t_value	*find_closest(t_stack *stack_a, t_sensor *data)
{
	t_value	*top;
	t_value	*bottom;

	data->top_pos = 0;
	top = stack_a->top;
	while (top->rank >= data->limit
		|| top->rank >= (int)stack_a->init_size - 3)
	{
		data->top_pos++;
		top = top->next;
	}
	bottom = stack_a->top;
	data->bottom_pos = 0;
	while (bottom->rank >= data->limit
		|| bottom->rank >= (int)stack_a->init_size - 3)
	{
		data->bottom_pos++;
		bottom = bottom->prev;
	}
	if (data->top_pos < data->bottom_pos)
		return (top);
	return (bottom);
}

void	handle_rot(t_stack *stack_a, t_stack *stack_b, t_sensor *data)
{
	if (data->top_pos < data->bottom_pos)
	{
		if (data->rb_pending)
		{
			rr(stack_a, stack_b, 0);
			data->rb_pending = 0;
		}
		else
			ra(stack_a, stack_b, 0);
	}
	else
		rra(stack_a, stack_b, 0);
}
