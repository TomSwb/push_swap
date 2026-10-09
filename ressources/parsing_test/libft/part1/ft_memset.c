/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:48:37 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/02 00:05:52 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Returns the given 's' array filled with the 'c' char up to 'n' bytes.

* @param void *s 
* @param int c 
* @param size_t n 
* @return void* 
*/

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*u_s;
	unsigned char	u_c;

	u_c = (unsigned char)c;
	u_s = (unsigned char *)s;
	while (n > 0)
	{
		*u_s = u_c;
		u_s++;
		n--;
	}
	return (s);
}
