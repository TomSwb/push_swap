/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:29:50 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/02 00:07:57 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Appends 'new' to the front of 'lst', making new->next point to either NULL
or the address of the original first node of lst.

* @param t_list **lst 
* @param t_list *node
*/

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (node == NULL || lst == NULL)
		return ;
	node->next = *lst;
	*lst = node;
}
