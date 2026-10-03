/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:08:56 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:54:46 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Returns the total length of the attempted concatenation, 
strlen(dst) + strlen(src) if successful or size + strlen(src) if the buffer dst
has no '\0' char within size bytes which does not result in a concatenation.

* @param char *dst 
* @param char const *src 
* @param size_t size 
* @return size_t 
*/

#include "../libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	len_src;

	i_src = 0;
	while (src[i_src])
		i_src++;
	len_src = i_src;
	i_dest = 0;
	while (i_dest < size && dst[i_dest])
		i_dest++;
	if (i_dest == size)
		return (size + i_src);
	i_src = 0;
	while (i_src < (size - 1) - i_dest && src[i_src])
	{
		dst[i_dest + i_src] = src[i_src];
		i_src++;
	}
	dst[i_dest + i_src] = '\0';
	return (i_dest + len_src);
}
