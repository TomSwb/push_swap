/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_moving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:25:12 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 17:30:28 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
GOAL : Rotates stack A to bring the "winner" sensor to the top and tries
	to do double move when possible
Return : void
*/
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

/*
GOAL : Same but with sensor [3] and [4] :Rotates stack A to bring the "winner"
	sensor to the top and tries to do double move when possible
Return : void
*/
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

/*
GOAL : Moves back the top of stack A after the "winner" was moved to stack B
Return : void
*/
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

/*
GOAL : Rotates stack B so that, when the top value of A is pushed,
	it ends next to the corresponding bucket
Return : void
*/
void	rotating_b (t_stack *s_a, t_stack *s_b, t_sensor *snr)
{
	int	rota;
	if (!snr->r || !snr->rr)
	{
		pb(s_a, s_b);
		return ;
	}
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
}