/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:24:37 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 13:48:31 by tschwab          ###   ########.ch       */
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
	int		a_r;
	int		a_rr;
	int		b_r;
	int		b_rr;
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
int	element_cost(t_stack *stack, t_cheapest *cheapest, t_value *value);

// on2_utils.c
t_value	*find_max_node(t_stack *stack);
t_value	*find_min_node(t_stack *stack);
int		is_sort(t_stack *stack);
void	init_cheapest(t_cheapest *cheapest);

#endif