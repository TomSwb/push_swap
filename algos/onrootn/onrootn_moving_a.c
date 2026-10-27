/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_moving_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:32:02 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 20:32:28 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

void	win_to_top(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	windex;

	windex = snr[0]->winner;
	if (windex == 0 && snr[windex]->rr <= snr[windex]->r)
	{
		rrr (s_a, s_b);
		rrr (s_a, s_b);
		snr[0]->rr -= 2;
	}
	if (windex == 0 && snr[windex]->rr > snr[windex]->r)
	{
		rra (s_a, s_b, 0);
		rra (s_a, s_b, 0);
	}
	if (windex == 1 && snr[windex]->rr <= snr[windex]->r)
	{
		rrr (s_a, s_b);
		snr[1]->rr -= 1;
	}
	if (windex == 1 && snr[windex]->rr > snr[windex]->r)
		rra (s_a, s_b, 0);
	if (windex >= 3)
		win_to_top_2(s_a, s_b, snr);
}

void	win_to_top_2(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	windex;

	windex = snr[0]->winner;
	if (windex == 3 && snr[windex]->r <= snr[windex]->rr)
	{
		rr (s_a, s_b);
		snr[3]->r -= 1;
	}
	if (windex == 3 && snr[windex]->r > snr[windex]->rr)
		ra (s_a, s_b, 0);
	if (windex == 4 && snr[windex]->r <= snr[windex]->rr)
	{
		rr (s_a, s_b);
		rr (s_a, s_b);
		snr[4]->r -= 2;
	}
	if (windex == 4 && snr[windex]->r > snr[windex]->rr)
	{
		ra (s_a, s_b, 0);
		ra (s_a, s_b, 0);
	}
}

void	moving_back(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	windex;

	windex = snr[0]->winner;
	if (windex == 0 && snr[windex]->rr > snr[windex]->r)
	{
		rr (s_a, s_b);
		rr (s_a, s_b);
	}
	if (windex == 0 && snr[windex]->rr < snr[windex]->r)
	{
		ra (s_a, s_b, 0);
		ra (s_a, s_b, 0);
	}
	if (windex == 1 && snr[windex]->rr > snr[windex]->r)
		rr (s_a, s_b);
	if (windex == 1 && snr[windex]->rr < snr[windex]->r)
		ra (s_a, s_b, 0);
	if (windex == 3 && snr[windex]->r > snr[windex]->rr)
		rrr (s_a, s_b);
	if (windex == 3 && snr[windex]->r < snr[windex]->rr)
		rra (s_a, s_b, 0);
	if (windex == 4)
		win_to_top_2(s_a, s_b, snr);
}

void	moving_back_2(t_stack *s_a, t_stack *s_b, t_sensor **snr)
{
	int	windex;

	windex = snr[0]->winner;
	if (windex == 4 && snr[windex]->r > snr[windex]->rr)
	{
		rrr (s_a, s_b);
		rrr (s_a, s_b);
	}
	if (windex == 4 && snr[windex]->r < snr[windex]->rr)
	{
		rra (s_a, s_b, 0);
		rra (s_a, s_b, 0);
	}
}