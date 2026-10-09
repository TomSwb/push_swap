/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:20:38 by tomswb            #+#    #+#             */
/*   Updated: 2026/08/29 16:36:25 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
If c is a lowercase letter, toupper() returns  its  uppercase  equivalent, 
if an uppercase representation exists in the current locale.  
Otherwise, it  returns  c.
* 
* @param int c 
* @return int 
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
