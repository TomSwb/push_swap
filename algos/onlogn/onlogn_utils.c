/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:38:44 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 15:40:22 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

t_chunk new_chunk(t_loc loc, int min, int max)
{
    t_chunk chunk;
    
    chunk.loc = loc;
    chunk.min = min;
    chunk.max = max;
    return (chunk);
}

void	two_elements_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a, stack_b, 0);
	return ;
}
