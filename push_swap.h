
#ifndef "PUSH_SWAP_H"
# define "PUSH_SWAP_H"

// --- Libraries --- //

// libft
# include "./libft/libft.h"

// --- Struct --- //

typedef struct s_stack 
{
    t_node *top;
    int     size;
    // something else?
} t_stack;

typedef struct s_node
{
    int value;
    // int index?
    // something else?
    // struct s_node *previous; ???
    struct s_node *next;
} t_node;

// --- Functions --- //

// main.c

// parsing.c

// parsing_utils.c

// complexity.c

// moves_a.c

// moves_b.c

// simple_algo.c

// medium_algo.c

// complex_algo.c

// bench.c

// utils.c

#endif