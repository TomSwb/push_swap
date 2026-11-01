/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:54:41 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 18:54:41 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

/*
BUCKET SORT with root(n) buckets. Push_swap-style!
1. Calculate root(n) 
	=> find_nxt_root
2. Assemble the values in root(n) all buckets
=> bucket 0 is in stack a, the others are in stack b in decreasing order
3. Sorting each bucket with a bubble sort
4. Merging them back together => all values of bucket 1, then bucket 2, ...
DONE
*/

void	bucket_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_sensor	**sensor;
	int			i;

	if (stack_a ->size >= 6)
	{
	sensor = malloc (sizeof(t_sensor *) * 5);
	if (!sensor)
		return ;
	i = sensor_alloc (sensor, stack_a);
	if (i != 5)
		freeing_snr(sensor, i);
	dispatch(stack_a, stack_b, sensor);
// ft_printf ("=== Post dispatch Stack A ===\n");
// print_buckets(stack_a, sensor[0], stack_a->size);
// ft_printf ("=== Post dispatch Stack B ===\n");
// print_buckets(stack_b, sensor[0], stack_b->size);
	sort_bucket (stack_a, stack_b, sensor[0]);
ft_printf ("=== Post sort Stack A ===\n");
print_buckets(stack_a, sensor[0], stack_a->size);
// ft_printf ("=== Post sort Stack B ===\n");
// print_buckets(stack_b, sensor[0], stack_b->size);
	freeing_snr(sensor, i);
	}
}

int	sensor_alloc (t_sensor **sensor, t_stack *stack_a)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		sensor[i] = malloc (sizeof (t_sensor));
		if (!sensor[i])
		{
			sensor[i] = NULL;	
			break ;
		}
		sensor[i]->n_buc = find_nxt_root(stack_a->init_size);
		sensor[i]->pos_malus = pos_mal(i);
	}
	return (i);
}


void	print_buckets(t_stack *stack, t_sensor *snr, int nb_to_print)
{
	t_value	*temp;
	int		rank_stop;
	int		i;

	i = 0;
	if (nb_to_print == 0)
		nb_to_print = stack->size;
	if (!stack->top)
		ft_printf ("empty stack\n");
	temp = stack->top;
	rank_stop = -1;
	ft_printf("size = %d\n", stack->size);
	while (temp && temp->rank != rank_stop && i < nb_to_print)
	{
		rank_stop = stack->top->rank;
		ft_printf ("buck : %-3d || rank : %-3d || value : %d\n", rk_to_buc(temp, snr), temp->rank, temp->value);
		temp = temp->next;
		i++;
	}
}