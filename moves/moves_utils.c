/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:43:46 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 15:43:57 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	moves_count(t_stack *stack_a)
{
	int	total_moves;

	total_moves = stack_a->moves.pa_moves + stack_a->moves.pb_moves
		+ stack_a->moves.sa_moves + stack_a->moves.sb_moves
		+ stack_a->moves.ss_moves + stack_a->moves.ra_moves
		+ stack_a->moves.rb_moves + stack_a->moves.rr_moves
		+ stack_a->moves.rra_moves + stack_a->moves.rrb_moves
		+ stack_a->moves.rrr_moves;
	return (total_moves);
}
