/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:59:01 by atardy            #+#    #+#             */
/*   Updated: 2026/10/22 16:00:07 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algos related libraries
# include "algos/on2/on2.h"
# include "algos/onlogn/onlogn.h"

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
	size_calculator(&stack_a);
	stack_a.size = stack_a.init_size;
	rank_parsing(&stack_a);
	disorder(&stack_a);
	tests(&stack_a, &stack_b);
	lstclear(&stack_a, 0);
	lstclear(&stack_b, 0);
	ft_printf("\nall works, lst cleared\n\n");
	return (0);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->disorder == 0)
		return ;
	else if (stack_a->disorder < 2000)
	{
		ft_printf("cost based insertion sort:\n");
		cost_based_insertion(stack_a, stack_b);
	}
	else if (stack_a->disorder >= 2000 && stack_a->disorder <= 5000)
		{}
	else
	{
		ft_printf("quick sort partioning sort:\n");
		quick_sort_partitioning(stack_a, stack_b);
	}
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
	ft_putendl_fd("Error", 2);
	return (1);
}
