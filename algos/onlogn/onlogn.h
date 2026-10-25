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

// === Structs === //

typedef enum e_loc
{
    TOP_A,
    BOT_A,
    TOP_B,
    BOT_B,
} t_loc;

typedef struct s_chunck
{
    t_loc loc;
    int min;
    int max;
} t_chunck;

// === Functions === //

// onlogn.c
void	quick_sort_partitioning(t_stack *stack_a, t_stack *stack_b);

// onlogn_utils.c
t_chunck new_chunck(t_loc loc, int min, int max);
void	two_elements_sort(t_stack *stack_a, t_stack *stack_b);

#endif