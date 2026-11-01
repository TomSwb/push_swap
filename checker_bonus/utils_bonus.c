/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:46:10 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/01 15:21:17 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
