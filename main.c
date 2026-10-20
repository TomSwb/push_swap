/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:59:01 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 18:15:31 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (write_error(1));
	stack_initializer(&stack_a);
	stack_initializer(&stack_b);
	if (flags_parsing(argc, argv, &stack_a))
		return (write_error(2));
	if (stack_a.flag == 0)
		stack_a.flag = 4;
	if (parsing(argc, argv, &stack_a) || check_double(&stack_a))
		return (lstclear(&stack_a, 1));
	stack_a.init_size = size_calculator(&stack_a);
	rank_parsing(&stack_a);
	disorder(&stack_a);
	tests(&stack_a, &stack_b);
	lstclear(&stack_a, 0);
	ft_printf("\nall works, lst cleared\n\n");
	return (0);
}

/*
GOAL : Write Error on std error. TEST ONLY : Can print where the error come from
	(also here to gain lines)
Return : always 1
*/
int	write_error(int n)
{
	// For test purpose
	if (n == 1)
		ft_printf("argc == 1\n");
	if (n == 2)
		ft_printf("flag parsing error or no int\n");
	if (n == 3)
		ft_printf("going through lstclear\n");
	if (n == 4)
		ft_printf("disorder fails\n");
	// Real function below
	(void) n;
	ft_printf("Error\n");
	return (1);
}
