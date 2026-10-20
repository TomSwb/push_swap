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

#include "../push_swap.h"

/*
GOAL : Swap the first two elements at the top of stack A.
	Do nothing if there is only one or no elements.
	write and increase count only if ss_bool is 0 (not called from ss)
Return : void
*/
void	sa(t_stack *stk_A, t_stack *stk_B, int ss_bool)
{
	t_value	*head;
	t_value	*second;

	(void) stk_B;
	if (!stk_A->top || stk_A->top->next == stk_A->top)
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
	if (!ss_bool)
	{
		ft_putendl_fd("sa", stk_A->fd);
		stk_A->moves++;
	}
}

/*
GOAL : Swap the first two elements at the top of stack B.
	Do nothing if there is only one or no elements.
	write and increase count only if ss_bool is 0 (not called from ss)
Return : void
*/
void	sb(t_stack *stk_A, t_stack *stk_B, int ss_bool)
{
	t_value	*head;
	t_value	*second;

	if (!stk_B->top || stk_B->top->next == stk_B->top)
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
	if (!ss_bool)
	{
		ft_putendl_fd("sb", stk_B->fd);
		stk_A->moves++;
	}
}

/*
GOAL : sa and sb at the same time. Calls them silently with arguments in
	reversed order so none of them prints or increase count
Return : void
*/
void	ss(t_stack *stk_A, t_stack *stk_B)
{
	if (!stk_A->top || !stk_B->top)
		return ;
	sa(stk_B, stk_A, 1);
	sb(stk_B, stk_A, 1);
	ft_putendl_fd("ss", stk_A->fd);
	stk_A->moves++;
}
