/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:42:15 by tomswb            #+#    #+#             */
/*   Updated: 2026/08/29 16:35:44 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief 
checks for an alphabetic character; in the standard  "C"
locale,  it is equivalent to (isupper(c) || islower(c)).
In some locales, there may be additional characters  for
which isalpha() is true—letters which are neither upper‐
case nor lowercase.

* @param int c 
* @return int 
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
