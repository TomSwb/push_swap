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
	data->chunk_size = find_nxt_root(stack_a->init_size);
	data->limit = data->chunk_size;
	data->pushed = 0;
	data->half = data->chunk_size / 2;
	data->top_pos = 0;
	data->bottom_pos = 0;
}

/*
GOAL : find i so that i * i is bigger or equal to the "size" parameter.
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
	while (top->rank >= data->limit)
	{
		data->top_pos++;
		top = top->next;
	}
	bottom = stack_a->top;
	data->bottom_pos = 0;
	while (bottom->rank >= data->limit)
	{
		data->bottom_pos++;
		bottom = bottom->prev;
	}
	if (data->top_pos < data->bottom_pos)
		return (top);
	return (bottom);
}
