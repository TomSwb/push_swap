/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:02:05 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/21 11:37:41 by atardy           ###   ########.fr       */
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
	print_values(stack_a, 0);
	print_ranks(stack_a);
	ft_printf("\n== Useless moves test ==\n");
	pa(stack_a, stack_b, 0);
	rb(stack_a, stack_b, 0);
	rr(stack_a, stack_b);
	rrb(stack_a, stack_b, 0);
	rrr(stack_a, stack_b);
	while (stack_a->top)
		pb (stack_a, stack_b);
	ft_printf("size stack_A = %d || size stack_B = %d\n", stack_a->size, stack_b->size);
	pb (stack_a, stack_b);
	ra (stack_a, stack_b, 0);
	rr(stack_a, stack_b);
	rra(stack_a, stack_b, 0);
	rrr(stack_a, stack_b);
	ft_printf("= END useless moves test =\nPutting some values back in stack_a\n");
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	ft_printf("size stack_A = %d || size stack_B = %d\n", stack_a->size, stack_b->size);
	ft_printf("\n== Testing moves ==\n");
	ft_printf("= Swaps =\n");
	ft_printf("First 2 stack_A elements before\n");
	print_values(stack_a, 2);
	ft_printf("First 2 stack_B elements before\n");
	print_values(stack_b, 2);
	sa(stack_a, stack_b, 0);
	sb(stack_a, stack_b, 0);
	ss(stack_a, stack_b);
	ft_printf("First 2 stack_A elements after (should be the same as before)\n");
	print_values(stack_a, 2);
	ft_printf("First 2 stack_B elements after (should be the same as before)\n");
	print_values(stack_b, 2);
	ft_printf("\n= Rotates & Reverse rotates =\n");
	ft_printf("Stack_A before\n");
	print_values(stack_a, 0);
	ft_printf("Stack_B before\n");
	print_values(stack_b, 0);
	ra (stack_a, stack_b, 0);
	rb (stack_a, stack_b, 0);
	rr (stack_a, stack_b);
	rra (stack_a, stack_b, 0);
	rrb (stack_a, stack_b, 0);
	rrr (stack_a, stack_b);
	ft_printf("Stack_A (should be the same as before)\n");
	print_values(stack_a, 0);
	ft_printf("Stack_B (should be the same as before)\n");
	print_values(stack_b, 0);
	ft_printf("\n== END testing moves ==\n");
	ft_printf("\nFinal moves count = %d\n", stack_a->moves);
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
	while (temp && temp->id != id_stop && i < nb_to_print)
	{
		id_stop = stack->top->id;
		ft_printf ("id : %-3d || value : %-5d \n", temp->id, temp->value);
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
		ft_printf("id : %-3d || value : %-5d || rank : %d\n", temp->id, temp->value, temp->rank);
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
