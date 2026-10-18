/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:43:21 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/18 12:53:16 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disorder(t_stack *stack_a)
{
	long long	mistakes;
	long long	total_pairs;

	mistakes = 10;
	total_pairs = 23;
	stack_a->disorder = mistakes * 10000 / total_pairs;
	ft_printf("%d.%02d%%", stack_a->disorder / 100, stack_a->disorder % 100);
}

int	main()
{
	t_stack	stack_a;
	t_value	*value1;
	t_value	*value2;
	t_value	*value3;
	t_value	*value4;

	stack_a.fd = 1;
	stack_a.size = 4;
	stack_a.disorder = 0;
	stack_a.top = value1;
	disorder(&stack_a);
}