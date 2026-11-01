/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:46:10 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 11:41:21 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
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
		 	return (1);
	}
	return (0);
}

t_move	check_what_move(char *s)
{
	static const char	*moves[11] = {"pa", "pb", "sa", "sb", "ss",
	"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int	i;
	
	i = 0;
	while (moves[i])
	{
		if (ft_strncmp(s, moves[i], ft_strlen(s)))
			return ((t_move)i);
		i++;
	}
	return (ERROR);
}
