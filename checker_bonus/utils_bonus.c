/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:46:10 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 10:51:40 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]) || (argv[i][0] == '-'
			&& ft_isdigit(argv[i][1])))
			i++;
		else
		 	return (0);
	}
	return (1);
}
