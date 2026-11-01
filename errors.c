/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:05:06 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 10:05:31 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : Write Error on std error. TEST ONLY : Can print where the error come from
	(also here to gain lines)
Return : always 1
*/
int	write_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}
