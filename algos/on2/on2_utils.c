/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:12:30 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/24 15:50:18 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "on2.h"

void	init_cheapest(t_cheapest *cheapest)
{
	cheapest->a_moves = 0;
	cheapest->b_moves = 0;
	cheapest->cost = INT_MAX;
	cheapest->element = NULL;
}

int	count_hops(t_stack *stack, t_value *node)
{
	int		i;
	t_value	*temp;

	i = 0;
	temp = stack->top;
	while (temp != node)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
