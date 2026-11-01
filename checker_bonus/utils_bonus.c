/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:46:10 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 12:47:07 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line/get_next_line.h"
#include "libft.h"
#include "push_swap.h"
#include <stddef.h>

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
	int					i;
	size_t				len;

	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	i = 0;
	while (i < ERROR)
	{
		if (!ft_strncmp(s, moves[i], ft_strlen(moves[i]) + 1))
			return ((t_move)i);
		i++;
	}
	return (ERROR);
}

void	free_line(char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
}
