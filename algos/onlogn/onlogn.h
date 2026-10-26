/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:37:58 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 14:47:28 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONLOGN_H
# define ONLOGN_H

// === Library === //

// push_swap.h -> for the structs
# include "../../push_swap.h"

// on2.h -> for the sort_first_three function
# include "../on2/on2.h"

// === Structs === //

typedef enum e_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B,
	NO_LOC,
}	t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	t_loc	loc_small;
	t_loc	loc_medium;
	t_loc	loc_big;
	int		min;
	int		max;
	int		pivot_low;
	int		pivot_high;
	int		size;
}	t_chunk;

// === Functions === //

// onlogn.c
void	quick_sort_partitioning(t_stack *stack_a, t_stack *stack_b);
void	sort_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk);

// onlogn_split.c
void	split_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);
void	split_top_a(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);
void	split_bot_a(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);
void	split_top_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);
void	split_bot_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);

// onlogn_small.c
void	sort_small_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk);
void	sort_three_b(t_stack *stack_a, t_stack *stack_b);
void	sort_three_a(t_stack *stack_a, t_stack *stack_b);
void	two_elements_sort(t_stack *stack_a, t_stack *stack_b);
void	move_to_top_a(t_stack *stack_a, t_stack *stack_b, t_loc loc);

// onlogn_utils.c
t_chunk	new_chunk(t_loc loc, int min, int max);

#endif