/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:50:50 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 11:50:53 by atardy           ###   ########.ch       */
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
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	sense_five(s_a, s_b, snr);
}

void	sense_five(t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	init_sensor (s_a->top->prev->prev, s_b, &snr[0]);
}

void	init_sensor (t_value *value_a, t_stack *s_b, t_sensor *snr)
{
	cost_rota (s_b, snr);
}
int	bucket_cmp(t_value *current, t_sensor *snr)
{
	int	diff;
	
	diff = (current->rank / snr->n_buc) - snr->bucket;
	return (diff);
}

void	new_finding(t_stack *s_b, t_sensor *snr)
{
	t_value	*current;
	int		nb_move;
	
	nb_move = -1;
	current = s_b->top;
	while (bucket_cmp(current, snr) > 0)
	{
		current = current->next;
		++nb_move;
	}
	while (bucket_cmp(current, snr) < 0) 
	{
		current = current->prev;
		++nb_move;
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





void	bucket_max(t_stack *s_a, t_stack *s_b, int n_buc)
{
	
	if (second.r == 0 && top.r != 0)
	{
		if (s_b->top->rank / n_buc == s_b->top->next->rank / n_buc
			&& s_b->top->rank < s_b->top->next->rank)
			ss(s_a, s_b);
		else
			sa(s_a, s_b, 0);
		ra (s_a, s_b, 0);
	}
	else if (top.r == 0)
	{
		if (second.r < second.rr)
			rr (s_a, s_b);
		else
			ra (s_a, s_b, 0);
	}
	
}
// new_finding cherche l'endroit où mettre le nouveau bucket


