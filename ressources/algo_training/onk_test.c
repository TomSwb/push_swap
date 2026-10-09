/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onk_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:18:16 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:48:21 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_training.h"

void	radix_test(void)
{
	int	len = 10;
	int	arr[10] = {7, 2, -9, 0, -5, 3, 8, 1, 6, 4};
	int	rev_arr[10] = {9, -8, 7, -6, 5, 4, 3, 2, 1, 0};
	int	str_arr[10] = {1, 0, 2, -3, 4, -5, 6, 7, 8, 9};
	int	end_arr[10] = {0, 1, -2, 3, -4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing radix:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_radix(arr, len);
	ft_printf("\nReverse:\n");
	test_radix(rev_arr, len);
	ft_printf("\nSorted:\n");
	test_radix(arr, len);
	ft_printf("\nLight start mixed:\n");
	test_radix(str_arr, len);
	ft_printf("\nLight end mixed:\n");
	test_radix(end_arr, len);
	ft_printf("\n");
}
