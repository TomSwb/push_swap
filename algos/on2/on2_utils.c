/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:12:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:24:46 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Resets cheapest to its starting values: moves at 0, element NULL
and cost at INT_MAX, so any real cost compares as cheaper.

* @param t_cheapest *cheapest
* @return void
*/
void	init_cheapest(t_cheapest *cheapest)
{
	cheapest->a_moves = 0;
	cheapest->b_moves = 0;
	cheapest->cost = INT_MAX;
	cheapest->element = NULL;
}

/**
* @brief
Counts the node's distance from the top of the stack, i.e. how many
ra/rb would bring it to the top. Reverse rotations are derived from
it by the caller (hops - size).
Requires node to be in the stack.

* @param t_stack *stack
* @param t_value *node
* @return int
*/
int	count_hops(t_stack *stack, t_value *node)
{
	int		i;
	t_value	*temp;

	i = 0;
	temp = stack->top;
	while (temp != node)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
