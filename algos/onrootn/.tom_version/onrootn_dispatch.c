/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:55:39 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 20:43:12 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "onrootn.h"
#include "structs.h"

/*
GOAL : keeps elements of bucket 0 in stack A, sends the other in stack B
	grouped by buckets!
No return value
*/
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor *data)
{
	t_value	*closest;

	while (s_a->top != NULL)
	{
		closest = find_closest(s_a, data);
		while (s_a->top != closest)
		{
			if (data->top_pos < data->bottom_pos)
				ra(s_a, s_b, 0);
			else
			 	rra(s_a, s_b, 0);
		}
		pb(s_a, s_b, 0);
		data->pushed++;
		if (closest->rank < data->half)
			rb(s_a, s_b, 0);
		if (data->pushed == data->limit)
		{
			data->limit += data->chunk_size;
			data->half += data->chunk_size;
		}	
	}
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
