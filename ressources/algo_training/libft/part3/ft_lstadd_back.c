/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:02:06 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/02 00:08:02 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Appends the given node 'new' to the end of 'lst'.

* @param t_list **lst 
* @param t_list *node
*/

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*ptr;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	ptr = *lst;
	while (ptr && ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = node;
}
