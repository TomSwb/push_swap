/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:14:13 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 11:14:13 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- Libraries --- //

// libft, malloc(), free(), read(), write(), exit()
# include "libft/libft.h"

// --- Struct --- //

typedef struct s_value
{
	int				value;
	int				id;
	int				rank;
	struct s_value	*prev;
	struct s_value	*next;
}	t_value;

typedef struct s_stack
{
	int		bench;
	int		flag;
	size_t	init_size;
	int		disorder;
	int		moves;
	t_value	*top;
}	t_stack;

// --- Functions --- //

// main.c
void	print_list(t_stack *stack_a);
int		write_error(int n);

// tests.c
void	tests(t_stack *stack_a);
void	print_values(t_stack *stack_a);
void	print_ranks(t_stack *stack_a);

// parsing.c
int		flags_parsing(int argc, char **argv, t_stack *s_a);
int		parsing(int argc, char **argv, t_stack *stack_a);
int		stack_from_split(char **int_lst, t_stack *stack_a);
int		pars_from_argv(int nb_int, char **int_lst, t_stack *stack_a);

// parsing_utils.c
int		check_int(char *content);
t_value	*lstnew(void *content, int id);
void	lstadd(t_stack *head, t_value *node);
int		lstclear(t_stack *head, int error);
int		check_double(t_stack *head);

// parsing_utils_2.c
void	stack_initializer(t_stack *st);
int		freeturn(char **int_lst);
size_t	size_calculator(t_stack *stk);

// disorder.c
int		disorder(t_stack *stack_a);
size_t	disorder_check(t_stack *stack_a, t_value *ptr_a,
			long long *mistakes, size_t i);
void	rank_parsing(t_stack *stack_a);

// s_moves.c

// p_moves.c

// r_moves.c
int		ra(t_stack *stack_a, t_stack *stack_b, int rr_bool);
int		rb(t_stack *stack_a, t_stack *stack_b, int rr_bool);
int		rr(t_stack *stack_a, t_stack *stack_b);

// rr_moves.c
int		rra(t_stack *stack_a, t_stack *stack_b, int rrr_bool);
int		rrb(t_stack *stack_a, t_stack *stack_b, int rrr_bool);
int		rrr(t_stack *stack_a, t_stack *stack_b);

// simple_algo.c

// medium_algo.c

// complex_algo.c

// bench.c

// utils.c

#endif
