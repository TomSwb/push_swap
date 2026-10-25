
#include "onlogn.h"

void	split_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    if (chunk.loc == TOP_A)
        split_top_a(stack_a, stack_b, chunk);
}

void split_top_a(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    int i;
    
    i = 0;
    while (i < chunk.size)
    {
        if (stack_a->top->rank < chunk.pivot_low)
        {
            pb(stack_a, stack_b);
            rb(stack_a, stack_b, 0);
        }
        else if (stack_a->top->rank < chunk.pivot_high)
            pb(stack_a, stack_b);
        else
            ra(stack_a, stack_b, 0);
        i++;
    }
}
