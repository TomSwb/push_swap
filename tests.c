/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:55:07 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 13:36:51 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tests(t_stack *stack_a)
{
	ft_printf("\n=== Tests ===\n");
	ft_printf("\nDisorder: %d.%02d%%\n", stack_a->disorder / 100,
		stack_a->disorder % 100);
	print_values(stack_a);
	print_ranks(stack_a);
}

void	print_values(t_stack *stack_a)
{
	size_t	i;
	t_value	*temp;

	temp = stack_a->top;
	i = 0;
	ft_printf("\nValues:\n");
	while (i < stack_a->init_size)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
		i++;
	}
}

void	print_ranks(t_stack *stack_a)
{
	size_t	i;
	t_value	*temp;

	temp = stack_a->top;
	i = 0;
	ft_printf("\nRanks:\n");
	while (i < stack_a->init_size)
	{
		ft_printf("%d\n", temp->rank);
		temp = temp->next;
		i++;
	}
}
