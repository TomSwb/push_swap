/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:59:01 by atardy            #+#    #+#             */
/*   Updated: 2026/10/26 18:16:23 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algos/on2/on2.h"
#include "algos/onlogn/onlogn.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (write_error());
	stack_initializer(&stack_a);
	stack_initializer(&stack_b);
	if (flags_parsing(argc, argv, &stack_a))
		return (write_error());
	if (stack_a.flag == 0)
		stack_a.flag = 4;
	if (parsing(argc, argv, &stack_a) || check_double(&stack_a))
		return (lstclear(&stack_a, 1));
	size_calculator(&stack_a);
	stack_a.size = stack_a.init_size;
	rank_parsing(&stack_a);
	disorder(&stack_a);
	push_swap(&stack_a, &stack_b);
	if (stack_a.bench)
		bench(&stack_a);
	lstclear(&stack_a, 0);
	lstclear(&stack_b, 0);
	return (0);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->strat = stack_a->flag;
	if (stack_a->disorder == 0 && stack_a->flag != 4)
		return ;
	else if (stack_a->flag == 1)
		cost_based_insertion(stack_a, stack_b);
	else if (stack_a->flag == 2)
		ft_printf("medium not implemented\n");
	else if (stack_a->flag == 3)
		quick_sort_partitioning(stack_a, stack_b);
	else if (stack_a->flag == 4)
		adaptive(stack_a, stack_b);
}

void	adaptive(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->strat = 1;
	if (stack_a->disorder < 2000)
	{
		if (stack_a->disorder != 0)
			cost_based_insertion(stack_a, stack_b);
	}
	else if (stack_a->disorder < 5000)
	{
		stack_a->strat = 2;
	}
	else
	{
		stack_a->strat = 3;
		quick_sort_partitioning(stack_a, stack_b);
	}
}

void	bench(t_stack *stack_a)
{
	print_disorder(stack_a);
	print_strategy(stack_a);
	print_ops(stack_a);
}

/*
GOAL : Write Error on std error. TEST ONLY : Can print where the error come from
	(also here to gain lines)
Return : always 1
*/
int	write_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}
