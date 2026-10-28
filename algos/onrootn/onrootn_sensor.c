/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:46:00 by atardy            #+#    #+#             */
/*   Updated: 2026/10/28 13:50:02 by atardy           ###   ########.ch       */
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
	
	if (s_a->size < 6)
		sort_small (s_a, s_b, snr[0]);
	while (s_b->size < 2)
	{
		if (rk_to_buc(s_a->top, snr[0]) == 0)
			ra(s_a, s_b, 0);
		else
			pb(s_a, s_b);
	}
	size_t	i;
	i = 0;
	while (!is_only_0(s_a, snr[0]) && s_a->size > 3 && i++ < s_a->init_size)
	{
// ft_printf("== Boucle start ==\n");
		sense_five(s_a, s_b, snr);
		if (snr[0]->winner == -1 || snr[0]->bucket == 0)
			edge_cases(s_a, s_b, snr);
		else
		{
// ft_printf ("top_b = %d(%d)\n", rk_to_buc(s_b->top, snr[0]), s_b->top->rank);
// ft_printf ("buck(rk) : snr0 = %d(%d) c:%d || snr1 = %d(%d) c:%d || snr2 = %d(%d) c:%d || snr3 = %d(%d) c:%d || snr4 = %d(%d) c:%d\n", snr[0]->bucket, snr[0]->node->rank, snr[0]->cost, snr[1]->bucket, snr[1]->node->rank, snr[1]->cost, snr[2]->bucket, snr[2]->node->rank, snr[2]->cost, snr[3]->bucket, snr[3]->node->rank, snr[3]->cost, snr[4]->bucket, snr[4]->node->rank, snr[4]->cost);
			if (snr[0]->winner != 2)
				win_to_top (s_a, s_b, snr);
if (s_a->top->rank != snr[snr[0]->winner]->node->rank)
	ft_printf("Winner pas au top!\n");
			rotating_b (s_a, s_b, snr[snr[0]->winner]);
			moving_back (s_a, s_b, snr);
		}
// ft_printf("windex = %d == Boucle End ==\n", snr[0]->winner);
	}
	ft_printf("Stack A post dispatch\n");
	print_buckets(s_a, snr[0], s_a->size);
	ft_printf("Stack B post dispatch\n");
	print_buckets(s_b, snr[0], s_b->size);
	if (!is_only_0(s_a, snr[0]) && s_a->size == 3)
		sort_three_a(s_a, s_b);
}

void	sense_five(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	init_sensor (s_a->top->prev->prev, s_b, snr[0], 0);
	init_sensor (s_a->top->prev, s_b, snr[1], 1);
	init_sensor (s_a->top, s_b, snr[2], 2);
	init_sensor (s_a->top->next, s_b, snr[3], 3);
	init_sensor (s_a->top->next->next, s_b, snr[4], 4);
	// int	i;
	// i = 0;
	// ft_printf ("ranks : -2 = %d || -1 = %d || 0 = %d || 1 = %d || 2 = %d\n", s_a->top->prev->prev->rank, s_a->top->prev->rank, s_a->top->rank, s_a->top->next->rank, s_a->top->next->next->rank);
	cost_adjust (snr);
	// while (i < 5)
	// {
	//	ft_printf ("snr[%d] : node->rank = %3d || bucket = %3d ||", i, snr[i]->node->rank, snr[i]->bucket);
	//	ft_printf (" r = %3d || rr = %3d || cost = %3d\n", snr[i]->r, snr[i]->rr, snr[i]->cost);
	// 	i++;
	// }
	snr[0]->winner = set_winner(snr, s_b);
	// ft_printf("windex = %d\n", snr[0]->winner);
}

int	set_winner(t_sensor **snr, t_stack *s_b)
{
	int	i;
	int	min_cost;
	int	min_index;
	
	i = -1;
	min_index = -1;
	min_cost = s_b->size + 10;
	while (++i < 5)
		if (snr[i]->cost >= 0 && (snr[i]->cost < min_cost
			||(snr[i]->cost == min_cost 
			&& snr[i]->pos_malus < snr[min_index]->pos_malus)))
		{
			min_index = i; 	
			min_cost = snr[i]->cost;
		}
	return (min_index);
}

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

// new_finding cherche l'endroit où mettre le nouveau bucket
void	new_finding(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	size_t	nb_move;
	
	nb_move = 0;
	current = s_b->top;
	while (!(rk_to_buc(current->prev, snr) > snr->bucket 
		&& rk_to_buc(current, snr) < snr->bucket) && nb_move < s_b->size)
	{
		current = current->next;
		nb_move++;
	}
	if (nb_move == s_b->size)
	{
		snr->rr = 0;
		snr->r = 0;
		return ;
	}
	snr->r = nb_move;
	snr->rr = s_b->size - nb_move;
}
