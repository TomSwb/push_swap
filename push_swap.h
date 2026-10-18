
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- Libraries --- //

// libft, malloc(), free(), read(), write(), exit()
# include "./libft/libft.h"

// --- Struct --- //

// or reuse the libft one?
typedef struct s_value 
{
	int				value;
	int				id;
	struct s_value	*previous;
	struct s_value	*next;
} t_value;

typedef struct s_stack 
{
	size_t	size;
	int		fd;
	int		disorder;
	t_value	*top;
} t_stack;

// --- Functions --- //

// main.c

// parsing.c

// parsing_utils.c

// disorder.c
void	disorder(t_stack *stack_a);
void	disorder_check(t_stack *stack_a, t_stack *temp, long long *mistakes);

// moves_a.c

// moves_b.c

// moves_both.c

// simple_algo.c

// medium_algo.c

// complex_algo.c

// bench.c

// utils.c

#endif