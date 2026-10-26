/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:23:58 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 15:52:56 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_disorder(t_stack *stack_a)
{
	ft_putstr_fd("[bench] ", 2);
}

void	print_strategy(t_stack *stack_a)
{
	ft_putstr_fd("[bench] ", 2);
}

void	print_ops(t_stack *stack_a)
{
	int	total_moves;

	total_moves = moves_count(stack_a);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_moves, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_count("sa:  ", stack_a->moves.sa_moves);
	print_count("  sb:  ", stack_a->moves.sb_moves);
	print_count("  ss:  ", stack_a->moves.ss_moves);
	print_count("  pa:  ", stack_a->moves.pa_moves);
	print_count("  pb:  ", stack_a->moves.pb_moves);
	ft_putchar_fd('\n', 2);
	print_rot(stack_a);
}

void	print_rot(t_stack *stack_a)
{
	ft_putstr_fd("[bench] ", 2);
	print_count("ra:  ", stack_a->moves.ra_moves);
	print_count("  rb:  ", stack_a->moves.rb_moves);
	print_count("  rr:  ", stack_a->moves.rr_moves);
	print_count("  rra:  ", stack_a->moves.rra_moves);
	print_count("  rrb:  ", stack_a->moves.rrb_moves);
	print_count("  rrr:  ", stack_a->moves.rrr_moves);
	ft_putchar_fd('\n', 2);
}

void	print_count(char *label, int count)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(count, 2);
}
