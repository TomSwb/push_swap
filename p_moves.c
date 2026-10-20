/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:35:56 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 12:39:48 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stk_A, t_stack *stk_B)
{
	t_value	*new_top_b;
	t_value	*to_fix;
	t_value	*old_top_a;
	
	if (stk_B->top == NULL)
		return ;
	old_top_a = stk_A->top;
	// if there's more than one node
	if (stk_B->top->next != NULL)
	{
		// disconnecting the head and repairing chain
		new_top_b = stk_B->top->next;
		to_fix = stk_B->top->next;
		to_fix->prev = stk_B->top->prev;
		to_fix = stk_B->top->prev;
		to_fix->next = stk_B->top->next;
	}
	// passing top B to top A
	stk_A->top = stk_B->top;
	// top B to new_top_B
	stk_B->top = new_top_b;
	if (old_top_a->next == NULL)
		
	


	
	
}