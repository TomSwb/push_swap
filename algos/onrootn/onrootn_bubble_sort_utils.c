/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_bubble_sort_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:58:14 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 17:58:43 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : Testes if the top of stack B is set to the 
	first element of the highest bucket
Return 1 : if it's so
Return 0 : if no
*/
int	buck_max_to_top (t_stack *s_b, t_sensor *snr)
{
	int	buck_max;

	buck_max = snr->max_buck;
	if (rk_to_buc(s_b->top, snr) != buck_max)
		return (0);
	if (rk_to_buc(s_b->top, snr) == rk_to_buc(s_b->top->prev, snr))
		return (0);
	return (1);
}

/*
GOAL : Testes if the ranks of the stack given as argument are sorted 
	decreasingly for stack A / increasingly for B depending of the rev_bool
Return 1 : if it's sorted
Return 0 : if no
*/
int	stack_is_sorted (t_stack *stk, int rev_bool)
{
	t_value	*current;
	size_t	i;
	current = stk->top;
	i = 0;
	while (i < stk->size - 1)
	{
		if (!rev_bool && current->rank > current->next->rank)
			return (0);
		else if (rev_bool && current->rank < current->next->rank)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

/*
GOAL : Tests which rotation is the shortest to bring the first element of
	of the highest bucket to the top of stack B
Return 1 : if Reverse Rotation is the shortest
Return 0 : if Rotation is the shortest
*/
int	rotation_side(t_stack *s_b, t_sensor *snr)
{
	int		buck_max;
	t_value	*current;
	size_t	nb_move;

	min_max_buck(s_b, snr);
	nb_move = 0;
	current = s_b->top;
	buck_max = snr->max_buck;
	if (rk_to_buc(s_b->top, snr) == buck_max)
		return (1);
	while (rk_to_buc(current, snr) != buck_max)
	{
		nb_move++;
		current = current->next;
	}
	if (nb_move < (s_b->size / 2))
	{
		return (0);
	}
	return (1);
}

/*
GOAL : Calculate the size of the bucket
Return : The size (number of elements) in the current bucket.
*/
int	bucket_size(t_stack *stk, t_sensor *snr)
{
	t_value	*current;
	int		buck_size;
	int		rank_stop;

	buck_size = 1;
	current = stk->top;
	rank_stop = stk->top->prev->rank;
	while (rk_to_buc(current, snr) == rk_to_buc(current->next, snr)
		&& current->rank != rank_stop)
	{
		buck_size++;
		current = current->next;
	}
	return (buck_size);
}

/*
GOAL : Sets up the min_rank and max_rank of snr with the corresponding ranks
	found while going through the bucket to the top of the stack.
Return : The size (number of elements) in the current bucket.
*/
int	min_max_rank(t_stack *stk, t_sensor *snr)
{
	t_value	*current;
	int		buck_size;
	int		i;

	snr->max_rank = -1;
	snr->min_rank = INT32_MAX;
	buck_size = bucket_size(stk, snr);
	current = stk->top;
	i = 0;
	while (i++ < buck_size)
	{
		if (current->rank > snr->max_rank)
			snr->max_rank = current->rank;
		if (current->rank < snr->min_rank)
			snr->min_rank = current->rank;
		current = current->next;
	}
	return (buck_size);
}

/*
GOAL : Tests if the top bucket of stack B is sorted or not. 
	DOESN'T WORK if there's only one bucket in stack B
Return 0 (No) : If bucket is not sorted (decreasingly)
Return 1 (Yes) : If bucket is sorted
*/
int	buck_is_sorted (t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	int		curr_buck;

	current = s_b->top;
	curr_buck = rk_to_buc(s_b->top, snr);
	while (rk_to_buc(current->next, snr) == curr_buck)
	{
		if (current->rank < current->next->rank)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
GOAL : Tests if all values of stack B belongs to the bucket 1 (which means
	that all others buckets were sorted and pushed back in B)
Return 0 (No) : If another bucket is in stack B
Return 1 (Yes) : If all value of stack B belongs in bucket 1
*/
int is_only_1(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	size_t	i;

	current = s_b->top;
	i = 0;
	while (i < s_b->size)
	{
		if (rk_to_buc(current, snr) != 1)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}