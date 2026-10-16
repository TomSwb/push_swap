
#ifndef "PUSH_SWAP_H"
# define "PUSH_SWAP_H"

// --- Libraries --- //

// libft
# include "./libft/libft.h"

// --- Struct --- //

typedef struct s_node
{

    struct s_node *next;
} t_node;

// --- Functions --- //

void push_swap(t_node *stack_a);

#endif