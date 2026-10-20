/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:47:04 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 16:47:18 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tests(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n=== Tests ===\n");
	ft_printf("\nDisorder: %d.%02d%%\n", stack_a->disorder / 100,
		stack_a->disorder % 100);
	print_values(stack_a);
	print_ranks(stack_a);
	pb(stack_a, stack_b);
	ft_printf("\nAfter one pb");
	ft_printf("\nLinks Stack_A\n");
	checking_links(stack_a);
	ft_printf("\nLinks Stack_B\n");
	checking_links(stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	ft_printf("\nAfter a few more pb");
	ft_printf("\nLinks Stack_A\n");
	checking_links(stack_a);
	ft_printf("\nLinks Stack_B\n");
	checking_links(stack_b);

	sa(stack_a, stack_b);
	ft_printf("\nStack A after sa\n");
	print_values(stack_a);
	sb(stack_a, stack_b);
	ft_printf("\nStack B after sb\n");
	print_values(stack_b);
	ss(stack_a, stack_b);
	ft_printf("\nAfter ss\n");
	ft_printf("Stack A\n");
	print_values(stack_a);
	ft_printf("\nStack B\n");
	print_values(stack_b);
	ft_printf("\nFinal link check");
	ft_printf("\nLinks Stack_A\n");
	checking_links(stack_a);
	ft_printf("\nLinks Stack_B\n");
	checking_links(stack_b);
	ft_printf("\nFinal moves count (expected 7) = %d\n", stack_a->moves);
	ft_printf("bench : %d || flag = %d\n", stack_a->bench, stack_a->flag);
}

void	print_values(t_stack *stack)
{
	t_value	*temp;
	int		id_stop;

	temp = stack->top;
	id_stop = -1;
	while (temp && temp->id != id_stop)
	{
		id_stop = stack->top->id;
		ft_printf ("id : %-3d || value : %-5d \n", temp->id, temp->value);
		temp = temp->next;
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

/*
GOAL : TEST ONLY! go through the stack given as argument and print
	if all links are biderectionnal or if a link is missing
Return : void
*/
void	checking_links(t_stack *stk)
{
	t_value	*head;
	t_value	*next;
	t_value	*prev;
	int		id_stop;

	head = stk->top;
	id_stop = -1;
	if (head == NULL)
		ft_printf ("stack vide\n");
	while (head && head->id != id_stop)
	{
		id_stop = stk->top->id;
		ft_printf ("id : %-3d || value : %-5d || ", head->id, head->value);
		next = head->next;
		prev = head->prev;
		if (!next)
			ft_printf ("next == NULL             ||");
		else if (next && head == next->prev)
			ft_printf ("Link with next : OK     || ");
		else 
			ft_printf ("Link with next : NOT OK || ");
		if (!prev)
			ft_printf ("prev == NULL\n");
		else if (head == prev->next)
			ft_printf ("Link with prev : OK\n");
		else 
			ft_printf ("Link with prev : NOT OK\n");
		head = next;
	}
}