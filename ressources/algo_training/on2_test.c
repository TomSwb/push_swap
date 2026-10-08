/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on2_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:16:16 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/08 14:21:37 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_training.h"

void	shell_test(void)
{
	int	len = 10;
	int	arr[10] = {7, 2, -9, 0, 5, 3, 8, 1, 6, 4};
	int	rev_arr[10] = {9, 8, -7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr[10] = {1, 0, -2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr[10] = {0, 1, -2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing shell_sort:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_shell(arr, len);
	ft_printf("\nReverse:\n");
	test_shell(rev_arr, len);
	ft_printf("\nSorted:\n");
	test_shell(arr, len);
	ft_printf("\nLight start mixed:\n");
	test_shell(str_arr, len);
	ft_printf("\nLight end mixed:\n");
	test_shell(end_arr, len);
	ft_printf("\n");
}

void	slct_test(void)
{
	int	len = 10;
	int	arr[10] = {7, 2, -9, 0, 5, 3, 8, 1, 6, 4};
	int	rev_arr[10] = {9, 8, -7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr[10] = {1, 0, -2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr[10] = {0, 1, -2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing selection_sort:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_slct(arr, len);
	ft_printf("\nReverse:\n");
	test_slct(rev_arr, len);
	ft_printf("\nSorted:\n");
	test_slct(arr, len);
	ft_printf("\nLight start mixed:\n");
	test_slct(str_arr, len);
	ft_printf("\nLight end mixed:\n");
	test_slct(end_arr, len);
	ft_printf("\n");
}

void	is_test(void)
{
	int	len = 10;
	int	arr[10] = {7, 2, -9, 0, 5, 3, 8, 1, 6, 4};
	int	rev_arr[10] = {9, 8, -7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr[10] = {1, 0, -2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr[10] = {0, 1, -2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing insertion_sort:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_is(arr, len);
	ft_printf("\nReverse:\n");
	test_is(rev_arr, len);
	ft_printf("\nSorted:\n");
	test_is(arr, len);
	ft_printf("\nLight start mixed:\n");
	test_is(str_arr, len);
	ft_printf("\nLight end mixed:\n");
	test_is(end_arr, len);
	ft_printf("\n");
}

void	css_test(void)
{
	int	len = 10;
	int	arr[10] = {7, 2, -9, 0, 5, 3, 8, 1, 6, 4};
	int	rev_arr[10] = {9, 8, -7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr[10] = {1, 0, -2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr[10] = {0, 1, -2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing cocktail_shaker_sort:");
	ft_printf("\n-----------------------\n");
	test_css(arr, len);
	test_css(rev_arr, len);
	test_css(arr, len);
	test_css(str_arr, len);
	test_css(end_arr, len);
	ft_printf("\n");
}

void	bs_test(void)
{
	int	len = 10;
	int	arr[10] = {7, 2, -9, 0, 5, 3, 8, 1, 6, 4};
	int	rev_arr[10] = {9, 8, -7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr[10] = {1, 0, -2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr[10] = {0, 1, -2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bubble_sort:");
	ft_printf("\n-----------------------\n");
	test_bs(arr, len);
	test_bs(rev_arr, len);
	test_bs(arr, len);
	test_bs(str_arr, len);
	test_bs(end_arr, len);
	ft_printf("\n");
}
