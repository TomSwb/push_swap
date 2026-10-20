/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:07:31 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 16:08:39 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : Swap the first two elements at the top of stack A.
	Do nothing if there is only one or no elements.
	write and increase count only if called with stkA & B in correct order
Return : void
*/
void	sa(t_stack *stk_A, t_stack *stk_B)
{
	t_value	*head;
	t_value	*second;
	
	if (stk_B->init_size == 0)
	{
		ft_putendl_fd("sa", stk_A->fd);
		stk_A->moves++;
	}
	if (!stk_A->top || !stk_A->top->next || !stk_A->top->prev)
		return ;
	head = stk_A->top;
	second = head->next;
	if (second->next == head)
		stk_A->top = second;
	else
	{
		head->next = second->next;
		head->next->prev = head;
		second->prev = head->prev;
		second->prev->next = second;
		second->next = head;
		head->prev = second;
		stk_A->top = second;
	}
}

/*
GOAL : Swap the first two elements at the top of stack B.
	Do nothing if there is only one or no elements.
	write and increase count only if called with stkA & B in correct order
Return : void
*/
void	sb(t_stack *stk_A, t_stack *stk_B)
{
	t_value	*head;
	t_value	*second;
	
	if (stk_B->init_size == 0)
	{
		ft_putendl_fd("sb", stk_B->fd);
		stk_A->moves++;	
	}
	if (!stk_B->top || !stk_B->top->next || !stk_B->top->prev)
		return ;
	head = stk_B->top;
	second = head->next;
	if (second->next == head)
		stk_B->top = second;
	else
	{
		head->next = second->next;
		head->next->prev = head;
		second->prev = head->prev;
		second->prev->next = second;
		second->next = head;
		head->prev = second;
		stk_B->top = second;
	}
}

/*
GOAL : sa and sb at the same time. Calls them with arguments in reversed
	order so none of them prints or increase count
Return : void
*/
void	ss(t_stack *stk_A, t_stack *stk_B)
{
	sa (stk_B, stk_A);
	sb (stk_B, stk_A);
	ft_putendl_fd("ss", stk_A->fd);
	stk_A->moves++;
}