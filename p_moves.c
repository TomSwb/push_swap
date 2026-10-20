/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:10:09 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 16:10:09 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
GOAL : Disconnect the first node of stack B, repair the chain 
	(or set it to NULL) if there's only one node left then ...
	Prints and counts only if pb_bool is 0 (not called from pb)
Return : void
*/
void	pa(t_stack *stk_A, t_stack *stk_B, int pb_bool)
{
	t_value	*temp_b;

	if (stk_B->top == NULL)
		return ;
	temp_b = stk_B->top->next;
	if (temp_b == stk_B->top)
		temp_b = NULL;
	else
	{
		temp_b = stk_B->top->prev;
		temp_b->next = stk_B->top->next;
		temp_b = stk_B->top->next;
		temp_b->prev = stk_B->top->prev;
	}
	pa_2(stk_A, stk_B, temp_b);
	stk_A->size--;
	stk_B->size++;
	if (!pb_bool)
	{
		ft_putendl_fd("pa", stk_A->fd);
		stk_A->moves++;
	}
}

/*
GOAL : ... take the disconnected node and put it on top of stack A
	and connect it with first and last node from the chain.
Return : void
*/
void	pa_2(t_stack *stk_A, t_stack *stk_B, t_value *temp_b)
{
	t_value	*temp_a;

	temp_a = stk_A->top;
	stk_A->top = stk_B->top;
	stk_B->top = temp_b;
	if (!temp_a)
	{
		stk_A->top->next = stk_A->top;
		stk_A->top->prev = stk_A->top;
		return ;
	}
	stk_A->top->next = temp_a;
	stk_A->top->prev = temp_a->prev;
	temp_a->prev = stk_A->top;
	temp_a = stk_A->top->prev;
	temp_a->next = stk_A->top;
}

/*
GOAL : Same as pa but for pb. calls pa silently with stacks in reverse order
Return : void
*/
void	pb(t_stack *stk_A, t_stack *stk_B)
{
	if (!stk_A->top)
		return ;
	pa(stk_B, stk_A, 1);
	ft_putendl_fd("pb", stk_B->fd);
	stk_A->moves++;
}
