/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:46:46 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:24:27 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Goes through every node of stack_b and stores in cheapest the one
needing the fewest moves to be pushed back into stack_a at its
right place, along with its a_moves, b_moves and total cost.
Requires stack_b not to be empty.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_cheapest *cheapest
* @return void
*/
void	find_cheapest(t_stack *stack_a, t_stack *stack_b, t_cheapest *cheapest)
{
	t_cheapest	current;
	size_t		i;
	t_value		*b_node;

	i = 0;
	b_node = stack_b->top;
	init_cheapest(cheapest);
	while (i < stack_b->size)
	{
		element_cost(stack_a, stack_b, &current, b_node);
		if (current.cost < cheapest->cost)
			*cheapest = current;
		b_node = b_node->next;
		i++;
	}
}

/**
* @brief
Computes the cheapest way to bring b_node and its target in stack_a
to the top, comparing the 4 rotation combos (both up, both down,
a up b down, a down b up), and stores it in current.
Positive moves mean rotate, negative mean reverse rotate.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_cheapest *current
* @param t_value *b_node
* @return void
*/
void	element_cost(t_stack *stack_a, t_stack *stack_b, t_cheapest *current,
	t_value *b_node)
{
	t_value	*target_node;
	int		a_up;
	int		b_up;
	int		a_down;
	int		b_down;

	init_cheapest(current);
	current->element = b_node;
	target_node = find_target_node(stack_a, b_node);
	a_up = count_hops(stack_a, target_node);
	b_up = count_hops(stack_b, b_node);
	a_down = a_up - (int)stack_a->size;
	b_down = b_up - (int)stack_b->size;
	set_if_cheapest(current, a_up, b_up, max_int(a_up, b_up));
	set_if_cheapest(current, a_down, b_down, max_int(-a_down, -b_down));
	set_if_cheapest(current, a_up, b_down, a_up - b_down);
	set_if_cheapest(current, a_down, b_up, b_up - a_down);
}

/**
* @brief
Overwrites current's a_moves, b_moves and cost with the incoming
values if cost is strictly lower than current->cost.
current->element is left untouched.

* @param t_cheapest *current
* @param int a_moves
* @param int b_moves
* @param int cost
* @return void
*/
void	set_if_cheapest(t_cheapest *current, int a_moves, int b_moves, int cost)
{
	if (cost < current->cost)
	{
		current->a_moves = a_moves;
		current->b_moves = b_moves;
		current->cost = cost;
	}
}

/**
* @brief
Return the higher int between a and b.

* @param int a
* @param int b
* @return int
*/
int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
