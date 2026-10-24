/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:24:37 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 14:46:27 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ON2_H
# define ON2_H

// === Library === //

// push_swap.h
# include "../../push_swap.h"

// === Struct === //

typedef struct s_cheapest
{
	int		a_moves;
	int		b_moves;
	int		cost;
	t_value	*element;
}	t_cheapest;

// === Functions === //

// on2.c
void	cost_based_insertion(t_stack *stack_a, t_stack *stack_b);
void	sort_first_three(t_stack *stack_a, t_stack *stack_b);
void	move_cheapest_node(t_stack *stack_a, t_stack *stack_b,
			t_cheapest *cheapest);

// on2_cost.c
void	find_cheapest(t_stack *stack_a, t_stack *stack_b,
			t_cheapest *cheapest);
void	element_cost(t_stack *stack_a, t_stack *stack_b, t_cheapest *current,
			t_value *b_node);
void	set_if_cheapest(t_cheapest *current, int a_moves, int b_moves,
			int cost);
int		max_int(int a, int b);

// on2_find_node.c
t_value	*find_max_node(t_stack *stack);
t_value	*find_min_node(t_stack *stack);
t_value	*find_target_node(t_stack *stack_a, t_value *b_node);

// on2_utils.c
int		is_sort(t_stack *stack);
void	init_cheapest(t_cheapest *cheapest);
int		count_hops(t_stack *stack, t_value *node);

#endif