/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlogn_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:38:44 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/25 17:32:29 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onlogn.h"

/**
* @brief
Returns a new chunk covering ranks min to max at location loc,
with its size computed (max - min + 1). 
The pivots (-1) and the three part locations (NO_LOC) are left unset,
for sort_chunk and split_chunk to fill.

* @param t_loc loc
* @param int min
* @param int max
* @return t_chunk
*/
t_chunk	new_chunk(t_loc loc, int min, int max)
{
	t_chunk	chunk;

	chunk.loc = loc;
	chunk.loc_small = NO_LOC;
	chunk.loc_medium = NO_LOC;
	chunk.loc_big = NO_LOC;
	chunk.min = min;
	chunk.max = max;
	chunk.pivot_low = -1;
	chunk.pivot_high = -1;
	chunk.size = chunk.max - chunk.min + 1;
	return (chunk);
}
