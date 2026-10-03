/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:53:32 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:55:05 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Searches the first n bytes of the given memory area for the byte value 
represented by c, and returns a pointer to the first matching byte or 
NULL if not found.

* @param void const s 
* @param int c 
* @param size_t n 
* @return void* 
*/

#include "../libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t				i;
	unsigned char		u_c;
	const unsigned char	*u_s;

	i = 0;
	u_c = (unsigned char)c;
	u_s = (unsigned char *)s;
	while (i < n)
	{
		if (u_s[i] == u_c)
			return ((void *)&u_s[i]);
		i++;
	}
	return (NULL);
}
