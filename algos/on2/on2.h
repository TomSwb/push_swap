/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:24:37 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 15:43:37 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ON2_H
# define ON2_H

// === Library === //

// push_swap.h
#include "../../push_swap.h"

// === Functions === //

// on2.c
void	cost_based_insertion(t_stack *stack_a, t_stack *stack_b);
void	sort_first_three(t_stack *stack_a, t_stack *stack_b);

// on2_utils.c
t_value	*find_max_node(t_stack *stack);
int		is_sort(t_stack *stack);

// cost.c

#endif