/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_tom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:04:23 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/22 16:15:38 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tests(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n=== Tests ===\n");
	ft_printf("\n== checking initial state ==\n");
	ft_printf("bench : %d || flag = %d\n", stack_a->bench, stack_a->flag);
	ft_printf("initial size stack_A = %d || initial size stack_B = %d\n",
		stack_a->init_size, stack_b->init_size);
	ft_printf("Disorder: %d.%02d%%\n", stack_a->disorder / 100,
		stack_a->disorder % 100);
	ft_printf("\nA\n");
	print_values(stack_a, 0);
	ft_printf("\nB\n");
	print_values(stack_b, 0);
	ft_printf("\n== Moves made ==\n");
	push_swap(stack_a, stack_b);
	ft_printf("\n== checking new state ==\n");
	ft_printf("\nA\n");
	print_values(stack_a, 0);
	ft_printf("moves count = %d\n", stack_a->moves);
	ft_printf("\nB\n");
	print_values(stack_b, 0);
}

void	print_values(t_stack *stack, int nb_to_print)
{
	t_value	*temp;
	int		id_stop;
	int		i;

	i = 0;
	if (nb_to_print == 0)
		nb_to_print = stack->size;
	if (!stack->top)
		ft_printf ("empty stack\n");
	temp = stack->top;
	id_stop = -1;
	ft_printf("init_size = %d\n", stack->init_size);
	ft_printf("size = %d\n", stack->size);
	while (temp && temp->id != id_stop && i < nb_to_print)
	{
		id_stop = stack->top->id;
		ft_printf ("id : %-3d || value : %-5d || rank : %d\n",
			temp->id, temp->value, temp->rank);
		temp = temp->next;
		i++;
	}
}
