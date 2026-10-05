
#include "algo_training.h"

int main(void)
{
	bs_test();
	is_test();
	slct_test();
	shell_test();
}

void shell_test(void)
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

void select_test(void)
{
	int len = 10;
	
	int arr1[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr1[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing slct_1:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_slct_1(arr1, len);
	ft_printf("\nReverse:\n");
	test_slct_1(rev_arr1, len);
	ft_printf("\nSorted:\n");
	test_slct_1(arr1, len);
	ft_printf("\nLight start mixed:\n");
	test_slct_1(str_arr1, len);
	ft_printf("\nLight end mixed:\n");
	test_slct_1(end_arr1, len);

	ft_printf("\n");
}

void is_test(void)
{
	int len = 10;
	
	int arr4[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr4[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr4[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr4[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
	
	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing is_4:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_is_4(arr4, len);
	ft_printf("\nReverse:\n");
	test_is_4(rev_arr4, len);
	ft_printf("\nSorted:\n");
	test_is_4(arr4, len);
	ft_printf("\nLight start mixed:\n");
	test_is_4(str_arr4, len);
	ft_printf("\nLight end mixed:\n");
	test_is_4(end_arr4, len);
	
	
	ft_printf("\n");
}


void bs_test(void)
{
	int len = 10;

	int arr5[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr5[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr5[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
	
	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_5:");
	ft_printf("\n-----------------------\n");
	test_bs_5(arr5, len);
	test_bs_5(rev_arr5, len);
	test_bs_5(arr5, len);
	test_bs_5(str_arr5, len);
	test_bs_5(end_arr5, len);

	ft_printf("\n");
}
