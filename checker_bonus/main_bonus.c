/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:08:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/14 10:16:13 by tschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

/**
* @brief
Reads the moves from stdin line by line (piped from push_swap or
typed by hand). Each line is checked and applied right away to
stack_a and stack_b. If a line is not a valid move, the rest of
stdin is drained and it returns 0 (Error). Otherwise it returns
is_sort's result once stdin is empty: 1 (OK) or -1 (KO).

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return int
*/
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

/**
* @brief
Applies the move given by checker by calling the matching move
function. The t_move enum keeps the comparisons readable. The last
argument is 1 so the move is done silently (not printed, not counted).

* @param t_stack *stack_a
* @param t_stack *stack_b
* @param t_move move
* @return void
*/
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

/**
* @brief
Checks the final state: returns -1 (KO) if stack_b is not empty.
Otherwise goes through stack_a from top to bottom, checking that
each number is smaller than the next one, and returns -1 as soon
as one is not. Returns 1 (OK) if the whole stack is in order
(an empty stack_a also counts as sorted).

* @param t_stack *stack_a
* @param t_stack *stack_b
* @return int
*/
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
