
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- Libraries --- //

// libft, malloc(), free(), read(), write(), exit()
# include "./libft/libft.h"

// --- Struct --- //

// or reuse the libft one?
typedef struct s_value 
{
    int value;
    int id;
    // something else?
    struct s_node *previous;
    struct s_node *next;
} t_value;

typedef struct s_stack 
{
    t_node *top;
    int     size;
    int     fd;
    // something else?
} t_stack;

// --- Functions --- //

// main.c

// parsing.c

// parsing_utils.c

// complexity.c

// moves_a.c

// moves_b.c

// moves_both.c

// simple_algo.c

// medium_algo.c

// complex_algo.c

// bench.c

// utils.c

#endif