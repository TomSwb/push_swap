/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:44:03 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 15:21:25 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// === Library === //

// push_swap.h
#include "push_swap.h"

// === Struct === //

typedef enum e_move
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	ERROR,
}	t_move;

// === Functions === //

// main_bonus.c
int		checker(t_stack *stack_a, t_stack *stack_b);
void	apply_move(t_stack *stack_a, t_stack *stack_b, t_move move);
int		is_sort(t_stack *stack_a, t_stack *stack_b);

// utils_bonus.c
t_move	check_what_move(char *s);
void	free_line(char *line);

#endif