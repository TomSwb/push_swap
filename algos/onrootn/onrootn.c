/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:48:19 by atardy            #+#    #+#             */
/*   Updated: 2026/11/02 00:32:42 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"
#include "push_swap.h"

/*
GOAL : Init the chunck data, then calls dispatch and bring_back to
sort the stack.

No return value
*/
void	bucket_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_sensor	data;

	init_data(stack_a, &data);
	dispatch(stack_a, stack_b, &data);
	sort_first_three(stack_a, stack_b);
	bring_back(stack_a, stack_b);
}

/*
GOAL : Sends all elements to s_b by chuncks, closest element of
the current chunck first.

No return value
*/
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor *data)
{
	t_value	*closest;

	while (s_a->size > 3)
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

/*
GOAL : Bring everything back to s_a, highest to lowest, faster
rotation sense way.

No return value
*/
void	bring_back(t_stack *s_a, t_stack *s_b)
{
	int		highest;
	t_value	*temp;
	size_t	pos;

	while (s_b->top != NULL)
	{
		temp = s_b->top;
		highest = s_b->size - 1;
		pos = 0;
		while(temp->rank != highest)
		{
			temp = temp->next;
			pos++;
		}
		while (s_b->top != temp)
		{
			if (pos < s_b->size / 2)
				rb(s_a, s_b, 0);
			else
			 	rrb(s_a, s_b, 0);
		}
		pa(s_a, s_b, 0);
	}
}
