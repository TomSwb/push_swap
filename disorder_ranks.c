/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_ranks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:43:21 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/20 18:13:28 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	disorder(t_stack *stack_a)
{
	t_value		*ptr_a;
	long long	mistakes;
	long long	total_pairs;
	size_t		i;

	if (stack_a->init_size < 2)
	{
		stack_a->disorder = 0;
		return ;
	}
	ptr_a = stack_a->top;
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_a->init_size - 1)
	{
		total_pairs += disorder_check(stack_a, ptr_a, &mistakes, i);
		ptr_a = ptr_a->next;
		i++;
	}
	stack_a->disorder = (((mistakes * 10000) + (total_pairs / 2))
			/ total_pairs);
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
	while (j < stack_a->init_size)
	{
		total_pairs++;
		if (ptr_a->value > ptr_b->value)
			(*mistakes)++;
		ptr_b = ptr_b->next;
		j++;
	}
	return (total_pairs);
}

void	rank_parsing(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*lowest_add;
	size_t	pass;
	size_t	i;

	pass = 0;
	while (pass < stack_a->init_size)
	{
		temp = stack_a->top;
		lowest_add = NULL;
		i = 0;
		while (i < stack_a->init_size)
		{
			if (temp->rank == -1 && (lowest_add == NULL
					|| lowest_add->value > temp->value))
				lowest_add = temp;
			temp = temp->next;
			i++;
		}
		lowest_add->rank = pass;
		pass++;
	}
}
