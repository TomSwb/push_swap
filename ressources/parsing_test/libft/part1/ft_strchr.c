/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:39:19 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:54:48 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Returns a pointer to the first matched character 
or NULL  if the character is not found.  The terminating null byte is 
considered part of the string, so that if c is specified as '\0', 
this function returns a pointer to the terminator.

* @param char const *s 
* @param int c 
* @return char* 
*/

#include "../libft.h"

char	*ft_strchr(char const *s, int c)
{
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
