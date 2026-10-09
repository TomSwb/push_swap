/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:30:36 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:54:38 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Compares up to n characters of s1 and s2 as unsigned char values, stopping 
at a '\0' character. Returns the difference between the first pair of 
different characters, or 0 if no difference is found.

* @param char const *s1 
* @param char const *s2 
* @param size_t n 
* @return int 
*/

#include "../libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
