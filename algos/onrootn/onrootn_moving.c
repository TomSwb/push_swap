/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_moving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:47:23 by atardy            #+#    #+#             */
/*   Updated: 2026/10/28 13:47:23 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

void	win_to_top(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	win;
	
	win = snr[0]->winner;
	if (win == 0 && snr[win]->rr <= snr[win]->r && snr[win]->rr >= 2)
	{
		rrr (s_a, s_b);
		rrr (s_a, s_b);
		snr[0]->rr -= 2;
	}
	else if (win == 0)
	{
		rra (s_a, s_b, 0);
		rra (s_a, s_b, 0);
	}
	if (win == 1 && snr[win]->rr <= snr[win]->r && snr[win]->rr >= 1)
	{
		rrr (s_a, s_b);
		snr[1]->rr -= 1;
	}
	else if (win == 1)
		rra (s_a, s_b, 0);
	if (win >= 3)
		win_to_top_2(s_a, s_b, snr);
}

void	win_to_top_2(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	win;

	win = snr[0]->winner;
	if (win == 3 && snr[win]->r <= snr[win]->rr && snr[win]->r >= 1)
	{
		rr (s_a, s_b);
		snr[3]->r -= 1;
	}
	else if (win == 3)
		ra (s_a, s_b, 0);
	if (win == 4 && snr[win]->r <= snr[win]->rr && snr[win]->r >= 2)
	{
		rr (s_a, s_b);
		rr (s_a, s_b);
		snr[4]->r -= 2;
	}
	else if (win == 4)
	{
		ra (s_a, s_b, 0);
		ra (s_a, s_b, 0);
	}
}

void	moving_back(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	win;

	win = snr[0]->winner;
	if (win == 0)
	{
		ra(s_a, s_b, 0);
		ra(s_a, s_b, 0);
	}
	if (win == 1)
		ra (s_a, s_b, 0);
	if (win == 3)
		rra (s_a, s_b, 0);
	if (win == 4)
	{
		rra (s_a, s_b, 0);
		rra (s_a, s_b, 0);
	}
}

void	rotating_b (t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
// int rank_next;
// int	bucket_top;
// int	rank_prev;
	int	rota;
	// ft_printf ("snr->r = %d || snr->rr = %d\n", snr->r, snr->rr);
	if (!snr->r || !snr->rr)
	{
		pb(s_a, s_b);
// rank_next = rk_to_buc(s_b->top->next, snr);
// bucket_top = rk_to_buc(s_b->top, snr);
// rank_prev = rk_to_buc(s_b->top->prev, snr);
// ft_printf ("prev buck = %2d || top->buck = %2d || next->buck = %2d\n\n", rank_prev, bucket_top, rank_next);
		return ;
	}
	if (snr->r < snr->rr)
	{
		rota = snr->r;
		// ft_printf ("rota = %d", rota);
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
// rank_next = rk_to_buc(s_b->top->next, snr);
// bucket_top = rk_to_buc(s_b->top, snr);
// rank_prev = rk_to_buc(s_b->top->prev, snr);
// ft_printf ("prev buck = %2d || top->buck = %2d || next->buck = %2d\n\n", rank_prev, bucket_top, rank_next);
}