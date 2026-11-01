/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:55:39 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 20:43:12 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : keeps elements of bucket 0 in stack A, sends the other in stack B
	grouped by buckets!
No return value
*/
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	while (s_b->size < 1)
	{
		if (rk_to_buc(s_a->top, snr[0]) == 0)
			ra(s_a, s_b, 0);
		else
			pb(s_a, s_b);
	}
	while (!is_only_0(s_a, snr[0]) && s_a->size > 3)
	{
		sense_five(s_a, s_b, snr);
		if (snr[0]->winner == -1 || snr[0]->bucket == 0)
			edge_cases(s_a, s_b, snr);
		else
		{
			if (snr[0]->winner != 2)
				win_to_top (s_a, s_b, snr);
			rotating_b (s_a, s_b, snr[snr[0]->winner]);
			if (snr[0]->winner != 2)
				moving_back (s_a, s_b, snr);
		}
	}
}

/*
GOAL : Initiate the five "sensors" by gathering informations on the head of 
	the stack and his 4 neibourgh (prev-prev, prev, next & next-next)
	THEN adjust the cost and select the "winner", aka the on that we'll move
	to stack B
No return value
*/
void	sense_five(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	init_sensor (s_a->top->prev->prev, s_b, snr[0], 0);
	init_sensor (s_a->top->prev, s_b, snr[1], 1);
	init_sensor (s_a->top, s_b, snr[2], 2);
	init_sensor (s_a->top->next, s_b, snr[3], 3);
	init_sensor (s_a->top->next->next, s_b, snr[4], 4);
	cost_adjust (snr);
	snr[0]->winner = set_winner(snr, s_b);
}

/*
GOAL : Go through the 5 sensors and select the one with the better (adjusted)
	cost => the winner who will be moved to stack b.
Return : the index of the winning sensor (from 0 to 4)
*/
// int	set_winner(t_sensor **snr, t_stack *s_b)
// {
// 	int	i;
// 	int	min_cost;
// 	int	min_index;

// 	i = -1;
// 	min_index = -1;
// 	min_cost = s_b->size + 15;
// 	while (++i < 5)
// 		if (snr[i]->cost >= 0 && (snr[i]->cost < min_cost
// 			||(snr[i]->cost == min_cost 
// 			&& snr[i]->pos_malus < snr[min_index]->pos_malus)))
// 		{
// 			min_index = i; 	
// 			min_cost = snr[i]->cost;
// 		}
// 	return (min_index);
// }

int	set_winner(t_sensor **snr, t_stack *s_b)
{
	int	i;
	int	min_cost;
	int	min_index;

	i = -1;
	min_index = -1;
	min_cost = s_b->size + 15;
	while (++i < 4)
		if (snr[i]->cost >= 0 && (snr[i]->cost < min_cost
			||(snr[i]->cost == min_cost 
			&& snr[i]->pos_malus < snr[min_index]->pos_malus)))
		{
			min_index = i; 	
			min_cost = snr[i]->cost;
		}
	return (min_index);
}

/*
GOAL : Give one sensor his t_value, his bucket number, and 
	IF bucket nb = 0 => the value must stay in stack_a so the cost is set
		to a big number (so it'd never be selected)
	Then call "cost_rota" to set-up the r and rr elements.
	Cost is equal to the lowest between r and rr.
	IF r = rr, then cost is set to one of them depending of the index 
		(to maximize the double moves (rrr & rr) during sort_a)
No return value
*/
void	init_sensor(t_value *value_a, t_stack *s_b, t_sensor *snr, int index)
{
	snr->node = value_a;
	snr->bucket = rk_to_buc(value_a, snr);
	if (snr->bucket == 0)
	{
		snr->r = -10;
		snr->rr = -10;
		snr->cost = s_b->size + 10;
		return ;
	}
	cost_rota (s_b, snr);
	if (snr->r == snr->rr)
	{
		if (index < 2)
			snr->cost = snr->rr;
		else
			snr->cost = snr->r;
	}
	else if (snr->r < snr->rr)
		snr->cost = snr->r;
	else 
		snr->cost = snr->rr;
}

/*
GOAL : Find the spot where a new bucket needs to be placed in stack B
	Does so (mainly) by looking for a spot where the prev bucket nb is bigger 
	and the next bucket nb is lower. Then sets the r & rr costs using
	the number of moves needed to go to this spot.
Return -1 :	if the spot is already on top of b => so cost_rota set to 0 r && rr
			(can also be because there's only one bucket so every spot is valid)
Return 0 :	if it correctly found a spot to put the new bucket
*/
int	new_finding(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	size_t	nb_mov;

	current = s_b->top;	
	if (rk_to_buc(current->prev, snr) > snr->bucket 
		&& rk_to_buc(current, snr) < snr->bucket)
		return (-1);
	min_max_buck (s_b, snr);
	if (snr->max_buck == snr->min_buck)
		return (-1);
	nb_mov = 0;
	if (snr->min_buck > snr->bucket || snr->max_buck < snr->bucket)
		while (!(rk_to_buc(current, snr) > rk_to_buc(current->prev, snr)))
		{
			nb_mov++;
			current = current->next;
		}
	else
		nb_mov = new_finding_else(s_b, snr, current);
	if (nb_mov == s_b->size)
		return (-1);
	snr->r = nb_mov;
	snr->rr = s_b->size - nb_mov;
	return (0);
}

int	new_finding_else(t_stack *s_b, t_sensor *snr, t_value *current)
{
	size_t	nb_mov;
	
	nb_mov = 0;
	while (rk_to_buc(current->prev, snr) < snr->bucket && nb_mov++ < s_b->size)
		current = current->next;
	while (!(rk_to_buc(current->prev, snr) > snr->bucket 
		&& rk_to_buc(current, snr) < snr->bucket) && nb_mov++ < s_b->size)	
			current = current->next;
	return (nb_mov);
}