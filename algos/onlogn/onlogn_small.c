/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:31:48 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:24:52 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Sorts a chunk of 3 nodes or less and leaves it sorted on top of
stack_a.

3 nodes in stack_b: brought to the top of B first if at BOT_B,
then sort_three_b sorts them while pushing them to A.

Any other case: each node is brought to the top of A with
move_to_top_a, then sorted with two_elements_sort (2 nodes)
or sort_three_a (3 nodes). 1 node needs nothing more.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_chunk chunk
* @return void
*/
void	sort_small_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int	i;

	i = 0;
	if (chunk.size == 3 && (chunk.loc == TOP_B || chunk.loc == BOT_B))
	{
		if (chunk.loc == BOT_B)
		{
			rrb(stack_a, stack_b, 0);
			rrb(stack_a, stack_b, 0);
			rrb(stack_a, stack_b, 0);
		}
		sort_three_b(stack_a, stack_b);
		return ;
	}
	while (i < chunk.size)
	{
		move_to_top_a(stack_a, stack_b, chunk.loc);
		i++;
	}
	if (chunk.size == 2)
		two_elements_sort(stack_a, stack_b);
	else if (chunk.size == 3)
		sort_three_a(stack_a, stack_b);
}

/**
* @brief
Sorts the top 3 nodes of stack_a without touching the nodes below:
sorts the first two, then the 2nd and 3rd (with ra sa rra),
then the first two again if the swap moved a smaller one up.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	sort_three_a(t_stack *stack_a, t_stack *stack_b)
{
	two_elements_sort(stack_a, stack_b);
	if (stack_a->top->next->rank > stack_a->top->next->next->rank)
	{
		ra(stack_a, stack_b, 0);
		sa(stack_a, stack_b, 0);
		rra(stack_a, stack_b, 0);
	}
	two_elements_sort(stack_a, stack_b);
}

/**
* @brief
Moves the top 3 nodes of stack_b to the top of stack_a, sorted.
Each round: sb if the 2nd node of B is bigger, so the bigger one
goes first, then pa, then two_elements_sort fixes the top of A.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	sort_three_b(t_stack *stack_a, t_stack *stack_b)
{
	int	left;

	left = 3;
	while (left != 0)
	{
		if (left >= 2 && stack_b->top->rank < stack_b->top->next->rank)
			sb(stack_a, stack_b, 0);
		pa(stack_a, stack_b, 0);
		two_elements_sort(stack_a, stack_b);
		left--;
	}
}

/**
* @brief
Sorts the top 2 nodes of stack_a: sa if the first is bigger.
stack_b is only passed through to the move.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return void
*/
void	two_elements_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->rank > stack_a->top->next->rank)
		sa(stack_a, stack_b, 0);
	return ;
}

/**
* @brief
Brings one node from loc to the top of stack_a:
BOT_A: rra. BOT_B: rrb then pa. TOP_B: pa. TOP_A: nothing to do.

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_loc loc
* @return void
*/
void	move_to_top_a(t_stack *stack_a, t_stack *stack_b, t_loc loc)
{
	if (loc == BOT_A)
		rra(stack_a, stack_b, 0);
	else if (loc == BOT_B)
		rrb(stack_a, stack_b, 0);
	if (loc == TOP_B || loc == BOT_B)
		pa(stack_a, stack_b, 0);
}
