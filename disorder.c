/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:43:21 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/18 13:30:45 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	disorder(t_stack *stack_a)
{
	t_stack		temp;
	long long	mistakes;
	long long	total_pairs;
	int		i;
	int		j;

	temp = *stack_a;
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_a->size)
	{
		temp.top = stack_a->top->next;
		j = i + 1;
		while (j < temp.size)
		{
			total_pairs++;
			if (stack_a->top->value > temp.top->value)
			{
				
				mistakes++;
			}	
			temp.top = temp.top->next;
			j++;
		}
		stack_a->top = stack_a->top->next;
		i++;
	}
	stack_a->disorder = mistakes * 10000 / total_pairs;
}

int	main()
{
	t_stack	stack_a;
	t_value	value1;
	t_value	value2;
	t_value	value3;
	t_value	value4;

	stack_a.fd = 1;
	stack_a.size = 4;
	stack_a.disorder = 0;
	stack_a.top = &value1;

	value1.id = 1;
	value1.value = 2;
	value1.previous = &value4;
	value1.next = &value2;

	value2.id = 2;
	value2.value = 3;
	value2.previous = &value1;
	value2.next = &value3;

	value3.id = 3;
	value3.value = 1;
	value3.previous = &value2;
	value3.next = &value4;

	value4.id = 4;
	value4.value = 4;
	value4.previous = &value3;
	value4.next = &value1;
	
	disorder(&stack_a);
	ft_printf("%d.%02d%%", stack_a.disorder / 100, stack_a.disorder % 100);
}