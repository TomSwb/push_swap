/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:11:34 by tomswb            #+#    #+#             */
/*   Updated: 2026/08/29 16:35:40 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Checks for  any  printable  character  including
space.

* @param int c
* @return int 
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
