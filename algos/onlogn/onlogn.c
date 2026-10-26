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
	if (stack_a->size < 3)
	{
		ft_printf("two elements sort:\n");
		two_elements_sort(stack_a, stack_b);
	}
}