/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:09:34 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 21:20:35 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// --- Struct --- //

# include <stddef.h>

typedef struct s_value
{
	int				value;
	int				id;
	int				rank;
	struct s_value	*prev;
	struct s_value	*next;
}	t_value;

typedef struct s_moves
{
	int	pa_moves;
	int	pb_moves;
	int	sa_moves;
	int	sb_moves;
	int	ss_moves;
	int	ra_moves;
	int	rb_moves;
	int	rr_moves;
	int	rra_moves;
	int	rrb_moves;
	int	rrr_moves;
}	t_moves;

typedef struct s_stack
{
	int		bench;
	int		flag;
	size_t	init_size;
	size_t	size;
	int		disorder;
	int		strat;
	t_moves	moves;
	t_value	*top;
}	t_stack;

#endif