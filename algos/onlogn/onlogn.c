/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:41:47 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 15:55:51 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

void	quick_sort_partitioning(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk first;
	
	first = new_chunk(TOP_A, 0, (int)stack_a->size - 1);
    sort_chunk(stack_a, stack_b, first);
}

void	sort_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    int size;
    int pivot_low;
    int pivot_high;
    
    size = (chunk.max - chunk.min) + 1;
	if (size <= 3)
    {
        sort_small_chunk(stack_a, stack_b, chunk);
        return ;
    }
    pivot_low = chunk.min + size / 3;
    pivot_high = chunk.min + size * 2 / 3;
}

void sort_small_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    
}
