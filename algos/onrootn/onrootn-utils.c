/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:50:03 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 20:50:03 by atardy           ###   ########.ch       */
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

int	find_nxt_root(int size)
{
	int	i;
	
    i = 1;
    while (i * i <= size)
        i++;
    return (i);
}

int	pos_mal(int i)
{
	if (i == 0)
		return(4);
	if (i == 1)
		return (2);
	if (i == 2)
		return (0);
	if (i == 3)
		return (2);
	if (i == 4)
		return (4);
}

int rk_to_buc(t_value *val, t_sensor *snr)
{
	return (val->rank / snr->n_buc);
}