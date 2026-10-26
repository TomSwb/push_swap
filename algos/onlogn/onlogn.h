/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:37:58 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 15:54:52 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONLOGN_H
# define ONLOGN_H

// === Library === //

// push_swap.h
#include "../../push_swap.h"

// === Functions === //

// onlogn.c
void	quick_sort_partitioning(t_stack *stack_a, t_stack *stack_b);

// onlogn_utils.c
void	two_elements_sort(t_stack *stack_a, t_stack *stack_b);

#endif