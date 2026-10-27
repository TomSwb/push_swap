/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:58:28 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 19:58:28 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

int is_only_max(t_stack *s_a, t_sensor *snr)
{
	t_value	*current;
	int		i;

	current = s_a->top;
	i = -1;
	while (++i < s_a->size)
	{
		if (current->rank / snr->n_buc != snr->buck_max)
			return (0);
		current = current->next;
	}
	return (1);
}

int	bucket_cmp(t_value *current, t_sensor *snr)
{
	int	diff;
	
	diff = (current->rank / snr->n_buc) - snr->bucket;
	return (diff);
}

void	edge_cases(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	i;

	if (snr[0]->bucket = snr[0]->buck_max) // ra ou rr
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

void	cost_adjust (t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	i;

	i = -1;
	while (i < 5)
	{
		if ((i == 0 || i == 1) && snr[i]->rr < snr[i]->r)
			snr[i]->cost += (snr[i]->pos_malus / 2);
		if ((i == 0 || i == 1) && snr[i]->rr > snr[i]->r)
			snr[i]->cost += snr[i]->pos_malus;
		if ((i == 3 || i == 4) && snr[i]->r < snr[i]->rr)
			snr[i]->cost += (snr[i]->pos_malus / 2);
		if ((i == 0 || i == 1) && snr[i]->r > snr[i]->rr)
			snr[i]->cost += snr[i]->pos_malus;
	}
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
