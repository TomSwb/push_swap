/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_bring_back_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 01:10:17 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/02 01:37:55 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Finds the position of a node by its rank, walking down the
stack from the top until it reaches it. The position is the
distance from the top (0 = top).

* @param t_stack *stack
* @param int rank
* @return size_t
*/
size_t	find_pos(t_stack *stack, int rank)
{
	size_t	pos;
	t_value	*temp;

	pos = 0;
	temp = stack->top;
	while (temp->rank != rank)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}

/**
* @brief
Calculates how many moves it takes to bring the node at pos
to the top: pos moves with rotate, or size - pos moves with
reverse rotate. Returns whichever count is smaller.

* @param size_t pos
* @param size_t size
* @return size_t
*/
size_t	rot_cost(size_t pos, size_t size)
{
	if (size - pos < pos)
		return (size - pos);
	return (pos);
}

/**
* @brief
Brings the node at pos to the top of s_b: rb pos times if it
is in the top half, otherwise rrb (size - pos) times.
s_a is only passed because the move functions take both stacks.

* @param t_stack *s_a
* @param t_stack *s_b
* @param size_t pos
* @return void
*/
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
		while (i > 0)
		{
			rrb(s_a, s_b, 0);
			i--;
		}
	}
}

/**
* @brief
Used when the second highest value in s_b is cheaper to reach
than the highest: brings the second highest to the top and pushes
it to s_a, then does the same with the highest, then swaps them
with sa so they end in the right order.

* @param t_stack *s_a
* @param t_stack *s_b
* @return void
*/
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
