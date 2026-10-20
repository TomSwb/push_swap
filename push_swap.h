/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 08:19:46 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 08:19:53 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- Libraries --- //

// libft, malloc(), free(), read(), write(), exit()
# include "libft/libft.h"
// pour les tests
# include <stdio.h>

// --- Struct --- //

typedef struct s_value
{
    int				value;
    int 			id;
    struct s_value	*prev;
    struct s_value	*next;
} t_value;

typedef struct s_stack
{
    t_value	*top;
	int		bench;
	int		flag;
    int     size;
	int		disorder;
} t_stack;

// --- Functions --- //

// main.c

// parsing.c
int		flags_parsing(int argc, char **argv, t_stack *s_a);
int		parsing(int argc, char **argv, t_stack *stack_a);
int		stack_from_split(char **int_lst, t_stack *stack_a);
int		pars_from_argv(int nb_int, char **int_lst, t_stack *stack_a);
// parsing_utils.c
int		check_int(char *content);
t_value	*lstnew(void *content, int id);
void	lstadd(t_stack *head,t_value *new);
int		lstclear(t_stack *head);
int		check_double(t_stack *head);
// parsing_utils_2.c
void	stack_initializer(t_stack *st);
int		write_error(int n);
int		freeturn(char **int_lst);
// disorder.c
void	disorder(t_stack *stack_a);
size_t	disorder_check(t_stack *stack_a, t_value *ptr_a,
			long long *mistakes, size_t i);

// moves_a.c

// moves_b.c

// moves_both.c

// simple_algo.c

// medium_algo.c

// complex_algo.c

// bench.c

// utils.c

#endif
