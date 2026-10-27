/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:50:45 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 20:50:45 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

/*
while (nb de cas traité <init_size)
Si rank/n_buc = n_buc ==> si bucket max
	ra => on le met à la fin du stack a && i++;
Else
	Si le bucket du 1er élément est pas proche et que le bucket du 2ième élément est au bon endroit dans le stack (+ ou - 1);
	swap a, on traite le deuxième 
	calcul de distance de rotation pour arriver au bucket qui nous intéresse
*/

void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	i;

	i = -1;
	while (rk_to_buc(s_a->top, snr) == snr[0]->buck_max)
		ra(s_a, s_b, 0);
	pb(s_a, s_b);
	while (!is_only_max(s_a, snr[0] && s_a->size > 3))
	{
		sense_five(s_a, s_b, snr);
		if (snr[0]->winner == -10 || snr[0]->bucket == snr[0]->buck_max)
			edge_cases(s_a, s_b, snr);
		else
		{
			win_to_top (s_a, s_b, snr);
			if (s_a->top != snr[snr[0]->winner]->node)
				printf("Winner pas au top!\n");
			rotating_b (s_a, s_b, snr[snr[0]->winner]);
			moving_back (s_a, s_b, snr);
		}
		
	}
	if (!is_only_max && s_a->size == 3)
		sort_three_a(s_a, s_b);
}

void	sense_five(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	init_sensor (s_a->top->prev->prev, s_b, snr[0], 0);
	if (snr[0]->bucket = snr[0]->buck_max)
		bucket_max(s_a, s_b, snr);
	init_sensor (s_a->top->prev, s_b, snr[1], 1);
	init_sensor (s_a->top, s_b, snr[2], 2);
	init_sensor (s_a->top->next, s_b, snr[3], 3);
	init_sensor (s_a->top->next->next, s_b, snr[4], 4);
	cost_adjust (s_a, s_b, snr);
	snr[0]->winner = set_winner(s_a, s_b, snr);
}

int	set_winner(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	i;
	int	min_cost;
	int	min_index;
	int	tie;
	
	i = -1;
	min_cost = -1;
	tie = 0;
	while (++i < 5)
		if (snr[i]->cost >= 0 && (snr[i]->cost < min_cost
			||(snr[i]->cost == min_cost 
			&& snr[i]->pos_malus < snr[min_index]->pos_malus)))
		{
			min_index = i; 	
			min_cost = snr[i]->cost;
		}
	if (min_cost == -1)
		return (-1);
	return (min_index);
}

void	init_sensor(t_value *value_a, t_stack *s_b, t_sensor *snr, int index)
{
	snr->node = value_a;
	snr->bucket = rk_to_buc(value_a, snr);
	if (snr->bucket == snr->buck_max)
	{
		snr->r = -10;
		snr->rr = -10;
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

// new_finding cherche l'endroit où mettre le nouveau bucket
void	new_finding(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	int		nb_move;
	
	nb_move = 0;
	current = s_b->top;
	while (bucket_cmp(current, snr) > 0)
	{
		current = current->next;
		nb_move++;
	}
	while (bucket_cmp(current->prev, snr) < 0) 
	{
		current = current->prev;
		nb_move++;
	}
	if (bucket_cmp(s_b->top, snr) > 0)
	{
		snr->r = nb_move;
		snr->rr = s_b->size - nb_move;
		return ;
	}
	snr->rr = nb_move;
	snr->r = s_b->size - nb_move;
	return ;
}

void	cost_rota(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	int		nb_move;

	nb_move = 0;
	current = s_b->top;
	while (bucket_cmp(current, snr) != 0 && nb_move++ < s_b->size)
		current = current->next;
	if (nb_move == s_b->size)
		{
			new_finding(s_b, snr);
			snr->new = 1;
			return ;
		}
	else
		snr->r = nb_move;
	nb_move = 0;
	current = s_b->top;
	while (bucket_cmp(current, snr) != 0 && nb_move++ < s_b->size)
		current = current->prev;
	snr->rr = nb_move;
}



