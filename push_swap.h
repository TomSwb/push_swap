/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:31:37 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 16:31:37 by atardy           ###   ########.ch       */
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
	size_t	size;
	int		disorder;
	int		moves;
	int		fd;
	t_value	*top;
}	t_stack;

// --- Functions --- //

// main.c
void	print_list(t_stack *stack_a);
int		write_error(int n);
void	checking_links(t_stack *stk);

// tests.c
void	tests(t_stack *stack_a, t_stack *stack_b);
void	print_values(t_stack *stack);
void	print_ranks(t_stack *stack_a);
void	checking_links(t_stack *stk);

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
void	size_calculator(t_stack *stk, size_t size_var);

// disorder.c
void	disorder(t_stack *stack_a);
size_t	disorder_check(t_stack *stack_a, t_value *ptr_a,
			long long *mistakes, size_t i);
void	rank_parsing(t_stack *stack_a);

// s_moves.c
void	sa(t_stack *stk_A, t_stack *stk_B, int ss_bool);
void	sb(t_stack *stk_A, t_stack *stk_B, int ss_bool);
void	ss(t_stack *stk_A, t_stack *stk_B);

// p_moves.c
void	pa(t_stack *stk_A, t_stack *stk_B, int pb_bool);
void	pa_2(t_stack *stk_A, t_stack *stk_B, t_value *temp_b);
void	pb(t_stack *stk_A, t_stack *stk_B);

// r_moves.c
void	ra(t_stack *stack_a, t_stack *stack_b, int rr_bool);
void	rb(t_stack *stack_a, t_stack *stack_b, int rr_bool);
void	rr(t_stack *stack_a, t_stack *stack_b);

// rr_moves.c
void	rra(t_stack *stack_a, t_stack *stack_b, int rrr_bool);
void	rrb(t_stack *stack_a, t_stack *stack_b, int rrr_bool);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// simple_algo.c

// medium_algo.c

// complex_algo.c

// bench.c

// utils.c

#endif
