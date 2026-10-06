
#include "algo_training.h"

void merge_test(void)
{
	int len = 10;
	
	int arr1[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr1[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing shell_1:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_shell_1(arr1, len);
	ft_printf("\nReverse:\n");
	test_shell_1(rev_arr1, len);
	ft_printf("\nSorted:\n");
	test_shell_1(arr1, len);
	ft_printf("\nLight start mixed:\n");
	test_shell_1(str_arr1, len);
	ft_printf("\nLight end mixed:\n");
	test_shell_1(end_arr1, len);

	ft_printf("\n");
}