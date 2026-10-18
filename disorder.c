/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:43:21 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/18 14:43:11 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disorder(t_stack *stack_a)
{
	t_value		*ptr_a;
	long long	mistakes;
	long long	total_pairs;
	size_t		i;

	if (stack_a->size < 2)
	{
		stack_a->disorder = 0;
		return ;
	}
	ptr_a = stack_a->top;
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_a->size - 1)
	{
		total_pairs += disorder_check(stack_a, ptr_a, &mistakes, i);
		ptr_a = ptr_a->next;
		i++;
	}
	stack_a->disorder = mistakes * 10000 / total_pairs;
}

size_t	disorder_check(t_stack *stack_a, t_value *ptr_a,
						long long *mistakes, size_t i)
{
	t_value		*ptr_b;
	size_t		total_pairs;
	size_t		j;

	ptr_b = ptr_a->next;
	j = i + 1;
	total_pairs = 0;
	while (j < stack_a->size)
	{
		total_pairs++;
		if (ptr_a->value > ptr_b->value)
			(*mistakes)++;
		ptr_b = ptr_b->next;
		j++;
	}
	return (total_pairs);
}

/*
int	main(void)
{
	t_stack	stack_a;
	t_value	value1;
	t_value	value2;
	t_value	value3;

	stack_a.fd = 1;
	stack_a.size = 3;
	stack_a.disorder = 0;
	stack_a.top = &value1;
	value1.id = 1;
	value1.value = 17;
	value1.previous = &value3;
	value1.next = &value2;
	value2.id = 2;
	value2.value = 10;
	value2.previous = &value1;
	value2.next = &value3;
	value3.id = 3;
	value3.value = 18;
	value3.previous = &value2;
	value3.next = &value1;
	disorder(&stack_a);
	ft_printf("%d.%02d%%", stack_a.disorder / 100, stack_a.disorder % 100);
}
*/