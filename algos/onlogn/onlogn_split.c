
#include "onlogn.h"

void	split_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    if (chunk.loc == TOP_A)
        split_top_a(stack_a, stack_b, chunk);
    else if (chunk.loc == BOT_A)
        split_bot_a(stack_a, stack_b, chunk);
    else if (chunk.loc == TOP_B)
        split_top_b(stack_a, stack_b, chunk);
    else if (chunk.loc == BOT_B)
        split_bot_b(stack_a, stack_b, chunk);
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

void split_bot_a(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    int i;
    
    i = 0;
    while (i < chunk.size)
    {
        ra(stack_a, stack_b, 0);
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

void split_top_b(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    int i;
    
    i = 0;
    while (i < chunk.size)
    {
        if (stack_b->top->rank < chunk.pivot_low)
            rb(stack_a, stack_b, 0);
        else if (stack_b->top->rank < chunk.pivot_high)
        {
            pa(stack_a, stack_b, 0);
            ra(stack_a, stack_b, 0);
        }
        else
            pa(stack_a, stack_b, 0);
        i++;
    }
}

void split_top_b(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
    int i;
    
    i = 0;
    while (i < chunk.size)
    {
        rb(stack_a, stack_b, 0);
        if (stack_b->top->rank < chunk.pivot_low)
            rb(stack_a, stack_b, 0);
        else if (stack_b->top->rank < chunk.pivot_high)
        {
            pa(stack_a, stack_b, 0);
            ra(stack_a, stack_b, 0);
        }
        else
            pa(stack_a, stack_b, 0);
        i++;
    }
}
