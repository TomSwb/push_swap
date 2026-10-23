/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:46:46 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/23 15:59:39 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

t_value	*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_value *cheapest;
	int		a_r;
	int		a_rr;
	int		b_r;
	int		b_rr;

	cheapest = stack_b->top;
	
}

int	element_cost(t_stack *stack, t_value *value)
{
	int		cost;
	t_value	*temp;

	cost = 0;
	temp = stack->top;
	return (cost);
}
