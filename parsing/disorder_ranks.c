/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_ranks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:43:21 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:26:11 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief
Computes the disorder of stack_a before sorting: the share
of pairs (i < j) where the value at i is bigger than the
value at j, over all pairs. 0 = sorted, 100% = reversed.
Stored as an int x100 (0 to 10000) so --bench can print it
with two decimals without floats:
(mistakes * 10000 + total_pairs / 2) / total_pairs.
Integer division rounds down, so adding half of total_pairs
first rounds to the nearest value instead.
A stack of 0 or 1 node has a disorder of 0.

* @param t_stack *stack_a
* @return void
*/
void	disorder(t_stack *stack_a)
{
	t_value		*ptr_a;
	long long	mistakes;
	long long	total_pairs;
	size_t		i;

	if (stack_a->init_size < 2)
	{
		stack_a->disorder = 0;
		return ;
	}
	ptr_a = stack_a->top;
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_a->init_size - 1)
	{
		total_pairs += disorder_check(stack_a, ptr_a, &mistakes, i);
		ptr_a = ptr_a->next;
		i++;
	}
	stack_a->disorder = (((mistakes * 10000) + (total_pairs / 2))
			/ total_pairs);
}

/**
* @brief
Helper of disorder: compares the node ptr_a (at position i)
with every node after it in stack_a. Each pair where ptr_a's
value is bigger is a mistake, added to *mistakes.
Returns the number of pairs checked (init_size - i - 1).

* @param t_stack *stack_a
* @param t_value *ptr_a
* @param long long *mistakes
* @param size_t i
* @return size_t
*/
size_t	disorder_check(t_stack *stack_a, t_value *ptr_a,
						long long *mistakes, size_t i)
{
	t_value		*ptr_b;
	size_t		total_pairs;
	size_t		j;

	ptr_b = ptr_a->next;
	j = i + 1;
	total_pairs = 0;
	while (j < stack_a->init_size)
	{
		total_pairs++;
		if (ptr_a->value > ptr_b->value)
			(*mistakes)++;
		ptr_b = ptr_b->next;
		j++;
	}
	return (total_pairs);
}

/**
* @brief
Gives every node a rank from 0 (smallest value) to n - 1
(biggest), so the algorithms work on consecutive positive
ranks instead of raw values (negatives, gaps).
Each pass finds the smallest value not ranked yet
(rank == -1) and gives it the pass number. n passes over n
nodes: O(n²). Requires every rank set to -1 beforehand.

* @param t_stack *stack_a
* @return void
*/
void	rank_parsing(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*lowest_add;
	size_t	pass;
	size_t	i;

	pass = 0;
	while (pass < stack_a->init_size)
	{
		temp = stack_a->top;
		lowest_add = NULL;
		i = 0;
		while (i < stack_a->init_size)
		{
			if (temp->rank == -1 && (lowest_add == NULL
					|| lowest_add->value > temp->value))
				lowest_add = temp;
			temp = temp->next;
			i++;
		}
		lowest_add->rank = pass;
		pass++;
	}
}
