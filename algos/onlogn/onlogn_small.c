/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:31:48 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/25 17:39:34 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

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

void	two_elements_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->rank > stack_a->top->next->rank)
		sa(stack_a, stack_b, 0);
	return ;
}

void	move_to_top_a(t_stack *stack_a, t_stack *stack_b, t_loc loc)
{
	if (loc == BOT_A)
		rra(stack_a, stack_b, 0);
	else if (loc == BOT_B)
		rrb(stack_a, stack_b, 0);
	if (loc == TOP_B || loc == BOT_B)
		pa(stack_a, stack_b, 0);
}
