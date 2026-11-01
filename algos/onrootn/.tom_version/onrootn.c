/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:48:19 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 23:04:46 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (stack_a->size >= 6)
		sensor = malloc (sizeof(t_sensor *) * 5);
	else
		sensor = malloc (sizeof(t_sensor *) * 5);
	if (!sensor)
		return ;
	i = sensor_alloc(sensor, stack_a);
	if (i != 5)
		freeing_snr(sensor, i);
	dispatch(stack_a, stack_b, sensor);
	sort_bucket (stack_a, stack_b, sensor[0]);
	freeing_snr(sensor, i);
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
