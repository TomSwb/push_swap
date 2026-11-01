/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:08:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 15:29:58 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "structs.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		result;

	if (argc == 1)
		return (0);
	stack_initializer(&stack_a);
	stack_initializer(&stack_b);
	if (parsing(1, argv, &stack_a) || check_double(&stack_a))
		return (lstclear(&stack_a, 1));
	stack_a.size = stack_a.init_size;
	result = checker(&stack_a, &stack_b);
	if (result == 0)
		write_error();
	else if (result == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	lstclear(&stack_a, 0);
	lstclear(&stack_b, 0);
}

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	t_move	move;

	line = get_next_line(0);
	while (line != NULL)
	{
		move = check_what_move(line);
		if (move == ERROR)
			return (free_line(line), 0);
		else
			apply_move(stack_a, stack_b, move);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (is_sort(stack_a, stack_b));
}

void	apply_move(t_stack *stack_a, t_stack *stack_b, t_move move)
{
	if (move == PA)
		pa(stack_a, stack_b, 1);
	else if (move == PB)
		pb(stack_a, stack_b, 1);
	else if (move == SA)
		sa(stack_a, stack_b, 1);
	else if (move == SB)
		sb(stack_a, stack_b, 1);
	else if (move == SS)
		ss(stack_a, stack_b, 1);
	else if (move == RA)
		ra(stack_a, stack_b, 1);
	else if (move == RB)
		rb(stack_a, stack_b, 1);
	else if (move == RR)
		rr(stack_a, stack_b, 1);
	else if (move == RRA)
		rra(stack_a, stack_b, 1);
	else if (move == RRB)
		rrb(stack_a, stack_b, 1);
	else if (move == RRR)
		rrr(stack_a, stack_b, 1);
}

int	is_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;
	t_value	*last;

	if (stack_b->top != NULL)
		return (-1);
	if (stack_a->top == NULL)
		return (1);
	temp = stack_a->top;
	last = stack_a->top->prev;
	while (temp != last)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (1);
}
