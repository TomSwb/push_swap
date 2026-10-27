/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:19:21 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 11:19:21 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

/*
BUCKET SORT with root(n) buckets. (normal, not push_swap-style)
1. Calculate root(n)
2. Dispatch values in n bucket. Each value is in bucket[rank / root(n)]
3. Sorting each bucket with a On2 algorithm
4. Merging them back together => all values of bucket 1, then bucket 2, ...
DONE
*/
/*
BUCKET SORT with root(n) buckets. Push_swap-style!
1. Calculate root(n) 
	=> find_nxt_root
2. Calculating cost of reassembling all values of all buckets 
	=> cost_projection : 
4. Reassemble all buckets
5. Sorting each bucket with a On2 algorithm
6. Merging them back together => all values of bucket 1, then bucket 2, ...
DONE
*/


void	bucket_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_sensor	sensor[5];
	int			i;
	
	i = -1;
	while (++i < 5)
	{
		sensor[i].n_buc = find_nxt_root(stack_a->init_size);
		sensor[i].position = i - 2;
		sensor[i].buck_max = sensor[i].n_buc - 1;
	}
	dispatch(stack_a, stack_b, &sensor);
	
}