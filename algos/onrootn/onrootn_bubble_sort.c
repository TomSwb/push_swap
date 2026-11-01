/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_bubble_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:00:13 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 18:00:21 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

/*
GOAL : Sort stack A then one bucket from stack B, push it back in stack A
	then the next bucket in stack B, etc. Then rotate A to put the lowest
	value to the top.
Return : void
*/
void	sort_bucket (t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	int reverse_bool;

	reverse_bool = rotation_side(s_b, snr);
	while (stack_is_sorted(s_a, 0) == 0)
		sort_a (s_a, s_b, snr, reverse_bool);
	while (!buck_max_to_top(s_b, snr) && !reverse_bool)
		rb (s_a, s_b, 0);
	while (!buck_max_to_top(s_b, snr) && reverse_bool)
		rrb (s_a, s_b, 0);
	while (!is_only_1(s_b, snr))
	{		
		while (!buck_is_sorted(s_b, snr))
			sort_b_bucket(s_a, s_b, snr);
		push_back(s_a, s_b, snr);
	}
	while (!stack_is_sorted (s_b, 1))
		sort_b (s_a, s_b, snr);
	while (s_b->top->rank != snr->max_rank)
		rb(s_a, s_b, 0);
	push_back(s_a, s_b, snr);
	while (s_a->top->rank != 0)
		rra (s_a, s_b, 0);
}

/*
GOAL : Go through the stack_a and sort it through a bubble sort algorithm
	++ Also helps sorting b and moving when a "double-move" is possible
Return : void
*/
void	sort_a (t_stack *s_a, t_stack *s_b, t_sensor *snr, int rvrs)
{
	size_t	i;	

	min_max_rank(s_a, snr);
	i = 0;
	while (i++ <= s_a->size)
	{
		if (s_a->top->rank > s_a->top->next->rank
			&& !(s_a->top->rank == snr->max_rank 
			&& s_a->top->next->rank == snr->min_rank)
			&& rk_to_buc(s_b->top, snr) == rk_to_buc(s_b->top->next, snr)
			&& s_b->top->rank < s_b->top->next->rank)
			ss (s_a, s_b);
		else if (s_a->top->rank > s_a->top->next->rank
			&& !(s_a->top->rank == snr->max_rank && s_a->top->next->rank == snr->min_rank))
			sa (s_a, s_b, 0);
		if (!rvrs && !buck_max_to_top(s_b, snr))
			rr (s_a, s_b);
		else if (!rvrs)
			ra (s_a, s_b, 0);	
		if (rvrs && !buck_max_to_top(s_b, snr))
			rrr (s_a, s_b);
		else if (rvrs)
			rra (s_a, s_b, 0);
	}
}

/*
GOAL : Go through the bucket once, switching when needed, then comes back to
	the start of the bucket, also switching when needed.
Return : void
*/
void	sort_b_bucket(t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	int	curr_buck;
	int	i;

	i = 0;
	curr_buck = rk_to_buc(s_b->top, snr);
	if (rk_to_buc(s_b->top->next, snr) != curr_buck)
		return;
	while (rk_to_buc(s_b->top->next, snr) == curr_buck)
	{
		if (s_b->top->rank < s_b->top->next->rank 
			&& rk_to_buc(s_b->top->next, snr) == curr_buck)
			sb (s_a, s_b, 0);
		rb (s_a, s_b, 0);
		i++;
	}
	while (i-- > 0)
		rrb (s_a, s_b, 0);
	while (i-- > 0)
	{
		if (s_b->top->prev->rank < s_b->top->rank)
			sb (s_a, s_b, 0);
		rrb (s_a, s_b, 0);
	}
}

/*
GOAL : Pushes back the value found in b while they are from the same bucket
Return : void
*/
void	push_back(t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	int	curr_bucket;
	
	curr_bucket = rk_to_buc(s_b->top, snr);
	while (rk_to_buc(s_b->top, snr) == curr_bucket && s_b->size > 0)
		pa(s_a, s_b, 0);
}

/*
GOAL : Sort the stack B when there's only one bucket left in it
Return : void
*/
void	sort_b(t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	size_t	i;

	i = 0;
	min_max_rank(s_b, snr);
	while (i <= s_b->size)
	{
		if (s_b->top->rank < s_b->top->next->rank
			&& !(s_b->top->rank == snr->min_rank 
			&& s_b->top->next->rank == snr->max_rank))
			sb (s_a, s_b, 0);
		rb (s_a, s_b, 0);
		i++;
	}
}