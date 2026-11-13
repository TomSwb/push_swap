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

/**
* @brief
Initialises the data struct before the chunk sort starts:
computes the chunk size (square root of the stack size rounded
down, times 11/4 (= 2.75), the tweaker), sets the first chunk limit to
that size and half to half of it, and puts every counter and
position to 0.

* @param t_stack *stack_a
* @param t_sensor *data
* @return void
*/
void	init_data(t_stack *stack_a, t_sensor *data)
{
	int	tweaker;

	tweaker = find_nxt_root(stack_a->init_size) * 11 / 4;
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

/**
* @brief
Finds the node of the current chunk (rank below the limit, and not
one of the 3 largest that stay in A) that is closest to the top or
to the bottom of stack_a, so it can be moved to stack_b. Stores both
distances in top_pos and bottom_pos and returns the closer node.

* @param t_stack *stack_a
* @param t_sensor *data
* @return t_value *
*/
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

/**
* @brief
Does one rotation of stack_a toward the closest node of the current
chunk: ra if it is closer to the top, rra if it is closer to the
bottom. If stack_b has an rb waiting (saved in data->rb_pending),
it does rr instead of ra to save a move, and clears the flag.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_sensor *data
* @return void
*/
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
