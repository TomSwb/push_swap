/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:08:15 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 11:22:34 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	stack_initializer(&stack_a);
	stack_initializer(&stack_b);
	if (digit_check(argc, argv))
		return (write_error());
	if (parsing(argc, argv, &stack_a) || check_double(&stack_a))
		return (lstclear(&stack_a, 1));
	stack_a.size = stack_a.init_size;
	checker(&stack_a, &stack_b);
	lstclear(&stack_a, 0);
	lstclear(&stack_b, 0);
}

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*move;
	
	move = get_next_line(0);
	while (move != NULL)
	{
		if (check_if_move(move) == ERROR)
			return (0);
		move = get_next_line(0);
	}
}