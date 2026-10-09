/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 10:24:48 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/01 23:53:33 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
Returns an array 'char *' representing the given int 'n'.

Static:
    ft_intlen();

External:
	malloc();

* @param int n 
* @return char* 
*/

#include "../libft.h"

static size_t	ft_intlen(long num);

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	size_t	sign;
	long	num;

	num = n;
	len = ft_intlen(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	sign = 0;
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
		sign = 1;
	}
	result[len] = '\0';
	while (len > sign)
	{
		result[--len] = num % 10 + 48;
		num = num / 10;
	}
	return (result);
}

/**
* @brief 
Helper: gives us the size_t len of a given long

* @param num 
* @return size_t 
*/
static size_t	ft_intlen(long num)
{
	size_t	count;

	count = 0;
	if (num <= 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
