/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:11:18 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 17:12:34 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : find i so that i * i is bigger or equal to the "size" parameter.
Return value : i
*/
int	find_nxt_root(int size)
{
	int	i;
	
    i = 1;
    while (i * i <= size)
        i++;
    return (i - 1);
}

/*
GOAL : Calculates the bucket number corresponding to the rank of the value 
	given as argument.
Return value : The bucket number
*/
int rk_to_buc(t_value *val, t_sensor *snr)
{
	if (!val || !snr)
		return (-1);
	return (val->rank / (snr->n_buc));
}

/*
GOAL : Free the sensors if an allocation failed or at the end of the sort.
Return : void
*/
void	freeing_snr(t_sensor **snr, int i)
{
	while (i >= 0)
	{
		if (snr[i])
			free (snr[i]);
		snr[i] = NULL;
		i--;
	}
	free (snr);
	snr = NULL;
}
