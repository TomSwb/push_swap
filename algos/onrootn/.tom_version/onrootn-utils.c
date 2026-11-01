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
GOAL : returns the "position malus" based on the index of the sensor
	aka the cost of moving the top of stack A to the value pointed by the
	sensor and then moving it back in place.
Return value : the "position malus"
*/
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
	return (-1);
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
GOAL : Set the min_buck & max_buck to the highest and lowest bucket number
	found in the stack given as argument.
Return : void
*/
void	min_max_buck(t_stack *stack, t_sensor *snr)
{
	t_value	*current;
	size_t	nb_mov;
	
	snr->max_buck = 0;
	snr->min_buck = snr->n_buc * 2;
	nb_mov = 0;
	current = stack->top;
	while (nb_mov++ <= stack->size)
	{
		if (rk_to_buc(current, snr) > snr->max_buck)
			snr->max_buck = rk_to_buc(current, snr);
		if (rk_to_buc(current, snr) < snr->min_buck)
			snr->min_buck = rk_to_buc(current, snr);
		current = current->next;
	}
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
