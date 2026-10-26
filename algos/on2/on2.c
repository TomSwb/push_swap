/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:28:41 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 14:57:20 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

/**
* @brief
Sorts stack_a in ascending order with a cost-based insertion:
all but 3 nodes go to stack_b, then each one is inserted back
into stack_a choosing the cheapest move each time,
and the min is rotated to the top at the end.
Requires ranks normalized to 0..n-1.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	cost_based_insertion(t_stack *stack_a, t_stack *stack_b)
{
	t_cheapest	cheapest;
	int			min_hops;

	push_halves_to_b(stack_a, stack_b);
	sort_first_three(stack_a, stack_b);
	while (stack_b->top != NULL)
	{
		find_cheapest(stack_a, stack_b, &cheapest);
		move_cheapest_node(stack_a, stack_b, &cheapest);
	}
	min_hops = count_hops(stack_a, find_min_node(stack_a));
	while (stack_a->top->rank != 0)
	{
		if (min_hops <= (int)stack_a->size / 2)
			ra(stack_a, stack_b, 0);
		else
			rra(stack_a, stack_b, 0);
	}
}

/**
* @brief
Pushes nodes from stack_a to stack_b until 3 are left in stack_a.
Nodes ranked below half of stack_a's initial size are rotated
to the bottom of stack_b, the others stay on top, so stack_b
is roughly pre-split for the insertion phase.
Requires ranks normalized to 0..n-1.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	push_halves_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int			middle_rank;

	middle_rank = stack_a->size / 2;
	while (3 < stack_a->size)
	{
		pb(stack_a, stack_b);
		if (stack_b->top->rank < middle_rank)
			rb(stack_a, stack_b, 0);
	}
}

/**
* @brief
Sorts stack_a in ascending order (smallest on top) when it holds
only 3 nodes: the ones left after push_halves_to_b, or a chunk of
3 alone in stack_a in quick_sort_partitioning.
Also works on 2 nodes only if they are unsorted (a sorted pair
would get a useless rra + sa).
stack_b is unused, only passed through to the moves.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	sort_first_three(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*max;

	max = find_max_node(stack_a);
	if (stack_a->top == max)
		ra(stack_a, stack_b, 0);
	else if (stack_a->top->next == max)
		rra(stack_a, stack_b, 0);
	if (stack_a->top->rank > stack_a->top->next->rank)
		sa(stack_a, stack_b, 0);
}
