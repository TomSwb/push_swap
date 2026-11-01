/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:17:38 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 18:17:38 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

/*
GOAL : Go through the stack to know if there's only value of the bucket 0
Return 0 (No) : if it finds a value which doesn't belong to bucket 0
Return 1 (Yes) : if it only finds value that belongs in bucket 0
*/
int is_only_0(t_stack *s_a, t_sensor *snr)
{
	t_value	*current;
	size_t	i;

	current = s_a->top;
	i = 0;
	while (i < s_a->size)
	{
		if (rk_to_buc(current, snr) != 0)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
/*
GOAL : If the sensor[0] or all the sensors belongs to bucket 0, 
	rotates stack A accordingly
Return : void
*/
void	edge_cases(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	i;

	if (snr[0]->bucket == 0)
	{
		if (snr[snr[0]->winner]->r > snr[snr[0]->winner]->rr)
			rr (s_a, s_b);
		else 
			ra (s_a, s_b, 0);
		return ;
	}
	i = -1;
	if (snr[0]->winner == -10)
		while (++i < 3)
			ra (s_a, s_b, 0);
}

/*
GOAL : Adjusts the cost of each sensor depending of the position_malus and
	the possibility of doing double moves to spare some moves.
Return : void
*/
void	cost_adjust (t_sensor **snr)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if ((i == 0 || i == 1) && snr[i]->rr <= snr[i]->r 
			&& snr[i]->rr > (snr[i]->pos_malus / 2))
			snr[i]->cost += (snr[i]->pos_malus / 2);
		else if (i == 0 || i == 1)
			snr[i]->cost += snr[i]->pos_malus;
		if ((i == 3 || i == 4) && snr[i]->r <= snr[i]->rr
			&& snr[i]->r > (snr[i]->pos_malus / 2))
			snr[i]->cost += (snr[i]->pos_malus / 2);
		else if (i == 3 || i == 4)
			snr[i]->cost += snr[i]->pos_malus;
	}
}

/*
GOAL : Calculate the number of rb and rrb that it'd take to bring the bucket
	corresponding to the value of the sensor, to the top of stack b.
Return : void
*/
void	cost_rota(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	size_t	nb_move;

	nb_move = 0;
	current = s_b->top;
	while (rk_to_buc(current, snr) != snr->bucket && nb_move++ <= s_b->size)
		current = current->next;
	if (rk_to_buc(current, snr) != snr->bucket)
	{
		if (new_finding(s_b, snr) == -1)
		{
			snr->r = 0;
			snr->rr = 0;
		}
		return ;
	}
	else
		snr->r = nb_move;
	nb_move = 0;
	current = s_b->top;
	while (rk_to_buc(current->prev, snr) != snr->bucket 
		&& nb_move++ <= s_b->size)
		current = current->prev;
	snr->rr = nb_move;
}
