/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_rotating_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:50:57 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 21:05:10 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"
// plus d'égalité possible entre rr et r
void	rotating_b (t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	int	rota;

	if (snr->r < snr->rr)
	{
		rota = snr->r;
		while (rota-- != 0)
			rb(s_a, s_b, 0);
	}
	else
	{
		rota = snr->rr;
		while (rota-- != 0)
			rrb(s_a, s_b, 0);
	}
	pb(s_a, s_b);
	int rank_next = rk_to_buc(s_b->top->next->rank, snr);
	int	bucket_top = rk_to_buc(s_b->top->rank, snr);
	int	rank_prev = rk_to_buc(s_b->top->prev->rank, snr);
	printf ("prev buck = %3d || top->buck = %3d || next->buck = %3d", rank_prev, bucket_top, rank_next);
}