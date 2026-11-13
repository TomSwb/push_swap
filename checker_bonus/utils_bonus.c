/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:46:10 by tschwab           #+#    #+#             */
/*   Updated: 2026/11/03 15:42:47 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
* @brief
Finds which move a line read from stdin is (from push_swap or
typed by the user). The line must end with '\n', which is
stripped before comparing. Only the 11 exact move names are
accepted; anything else returns ERROR.

* @param char *s
* @return t_move
*/
t_move	check_what_move(char *s)
{
	static const char	*moves[11] = {"pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int					i;
	size_t				len;

	len = ft_strlen(s);
	if (len == 0 || s[len - 1] != '\n')
		return (ERROR);
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

/**
* @brief
Used when the checker hits an invalid move: frees the current line,
then keeps reading and freeing every remaining line of stdin until
get_next_line returns NULL. Draining stdin this way also lets
get_next_line free its static buffer, so nothing leaks.

* @param char *line
* @return void
*/
void	free_line(char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
}
