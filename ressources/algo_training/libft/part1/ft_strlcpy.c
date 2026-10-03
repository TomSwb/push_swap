/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:14:09 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:54:44 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Copies src into dest and returns the len of the wanted result (len of src)  

* @param char *dest 
* @param char const *src 
* @param size_t dsize 
* @return size_t result 
*/

#include "../libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t dsize)
{
	size_t	result;
	size_t	len;

	result = 0;
	while (src[result])
		result++;
	if (dsize == 0)
		return (result);
	len = 0;
	while (len < dsize - 1 && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (result);
}
