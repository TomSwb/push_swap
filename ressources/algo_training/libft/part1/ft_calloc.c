/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:22:12 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:55:13 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Allocates memory for n elements of size bytes each, initializes all 
allocated bytes to 0, and returns a pointer to the allocated memory.

External:
	malloc();

* @param size_t n 
* @param size_t size 
* @return void* 
*/

#include "../libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*array;
	void			*empty;
	size_t			i;

	if (n == 0 || size == 0)
	{
		empty = malloc(1);
		if (!empty)
			return (NULL);
		return (empty);
	}
	if (n > SIZE_MAX / size)
		return (NULL);
	array = malloc(size * n);
	if (!array)
		return (NULL);
	i = 0;
	while (i < (n * size))
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
