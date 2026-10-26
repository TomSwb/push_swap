/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:23:58 by tschwab           #+#    #+#             */
/*   Updated: 2026/10/26 18:10:50 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_disorder(t_stack *stack_a)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(stack_a->disorder / 100, 2);
	ft_putchar_fd('.', 2);
	if (stack_a->disorder % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(stack_a->disorder % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(t_stack *stack_a)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (stack_a->flag == 1)
		ft_putstr_fd("Simple", 2);
	else if (stack_a->flag == 2)
		ft_putstr_fd("Medium", 2);
	else if (stack_a->flag == 3)
		ft_putstr_fd("Complex", 2);
	else if (stack_a->flag == 4)
		ft_putstr_fd("Adaptive", 2);
	ft_putstr_fd(" / ", 2);
	if (stack_a->strat == 1)
		ft_putstr_fd("O(n²)", 2);
	else if (stack_a->strat == 2)
		ft_putstr_fd("O(n√n)", 2);
	else if (stack_a->strat == 3)
		ft_putstr_fd("O(n log n)", 2);
	ft_putchar_fd('\n', 2);
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
	ft_putstr_fd("[bench] ", 2);
	print_count("ra:  ", stack_a->moves.ra_moves);
	print_count("  rb:  ", stack_a->moves.rb_moves);
	print_count("  rr:  ", stack_a->moves.rr_moves);
	print_count("  rra:  ", stack_a->moves.rra_moves);
	print_count("  rrb:  ", stack_a->moves.rrb_moves);
	print_count("  rrr:  ", stack_a->moves.rrr_moves);
	ft_putchar_fd('\n', 2);
}

int	moves_count(t_stack *stack_a)
{
	int	total_moves;

	total_moves = stack_a->moves.pa_moves + stack_a->moves.pb_moves
		+ stack_a->moves.sa_moves + stack_a->moves.sb_moves
		+ stack_a->moves.ss_moves + stack_a->moves.ra_moves
		+ stack_a->moves.rb_moves + stack_a->moves.rr_moves
		+ stack_a->moves.rra_moves + stack_a->moves.rrb_moves
		+ stack_a->moves.rrr_moves;
	return (total_moves);
}

void	print_count(char *label, int count)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(count, 2);
}
