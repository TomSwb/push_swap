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
