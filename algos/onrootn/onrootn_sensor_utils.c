/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:51:16 by atardy            #+#    #+#             */
/*   Updated: 2026/10/28 13:51:16 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

void	sort_small(t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	(void) s_a;
	(void) s_b;
	(void) snr;
	ft_printf ("A REGLER\n");
}

int is_only_0(t_stack *s_a, t_sensor *snr)
{
	t_value	*current;
	size_t	i;

	current = s_a->top;
	i = 0;
	while (i < s_a->size)
	{
		if (current->rank / snr->n_buc != 0)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

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

void	cost_rota(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	size_t	nb_move;

	nb_move = 0;
	current = s_b->top;
	while (rk_to_buc(current, snr) != snr->bucket && ++nb_move < s_b->size)
		current = current->next;
	if (nb_move == s_b->size)
		{
			new_finding(s_b, snr);
			return ;
		}
	else
		snr->r = nb_move;
	nb_move = 0;
	current = s_b->top;
	while (rk_to_buc(current->prev, snr) != snr->bucket 
		&& nb_move++ < s_b->size)
		current = current->prev;
	snr->rr = nb_move;
}
