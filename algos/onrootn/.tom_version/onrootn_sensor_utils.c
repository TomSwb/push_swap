/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn_sensor_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:17:38 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 18:17:38 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : Go through the stack to know if there's only value of the bucket 0
Return 0 (No) : if it finds a value which doesn't belong to bucket 0
Return 1 (Yes) : if it only finds value that belongs in bucket 0
*/
int is_only_0(t_stack *s_a, t_sensor *snr)
{
	t_value	*current;
	size_t	i;

	current = s_a->top;
	i = 0;
	while (i < s_a->size)
	{
		if (rk_to_buc(current, snr) != 0)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
