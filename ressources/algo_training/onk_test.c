
#include "algo_training.h"

void radix_test(void)
{
	int len = 10;
	
	int arr1[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr1[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing radix_1:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_radix_1(arr1, len);
	ft_printf("\nReverse:\n");
	test_radix_1(rev_arr1, len);
	ft_printf("\nSorted:\n");
	test_radix_1(arr1, len);
	ft_printf("\nLight start mixed:\n");
	test_radix_1(str_arr1, len);
	ft_printf("\nLight end mixed:\n");
	test_radix_1(end_arr1, len);

    /*
    int arr2[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr2[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing radix_2:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_radix_2(arr2, len);
	ft_printf("\nReverse:\n");
	test_radix_2(rev_arr2, len);
	ft_printf("\nSorted:\n");
	test_radix_2(arr2, len);
	ft_printf("\nLight start mixed:\n");
	test_radix_2(str_arr2, len);
	ft_printf("\nLight end mixed:\n");
	test_radix_2(end_arr2, len);
    */

	ft_printf("\n");
}