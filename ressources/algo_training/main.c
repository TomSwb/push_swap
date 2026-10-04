
#include "algo_training.h"

int main(void)
{
	is_test();
	bs_test();
}

void is_test(void)
{
	int len = 10;
	
	int arr1[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr1[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing is_1:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_is_1(arr1, len);
	ft_printf("\nReverse:\n");
	test_is_1(rev_arr1, len);
	ft_printf("\nSorted:\n");
	test_is_1(arr1, len);
	ft_printf("\nLight start mixed:\n");
	test_is_1(str_arr1, len);
	ft_printf("\nLight end mixed:\n");
	test_is_1(end_arr1, len);

	
	int arr2[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4}; 
	int rev_arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr2[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing is_2:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_is_2(arr2, len);
	ft_printf("\nReverse:\n");
	test_is_2(rev_arr2, len);
	ft_printf("\nSorted:\n");
	test_is_2(arr2, len);
	ft_printf("\nLight start mixed:\n");
	test_is_2(str_arr2, len);
	ft_printf("\nLight end mixed:\n");
	test_is_2(end_arr2, len);


	int arr3[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr3[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr3[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing is_3:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_is_3(arr3, len);
	ft_printf("\nReverse:\n");
	test_is_3(rev_arr3, len);
	ft_printf("\nSorted:\n");
	test_is_3(arr3, len);
	ft_printf("\nLight start mixed:\n");
	test_is_3(str_arr3, len);
	ft_printf("\nLight end mixed:\n");
	test_is_3(end_arr3, len);
	
	
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
	
	/*
	int arr5[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr5[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr5[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
	
	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing is_5:");
	ft_printf("\n-----------------------\n");
	ft_printf("\nMixed:\n");
	test_is_5(arr5, len);
	ft_printf("\nReverse:\n");
	test_is_5(rev_arr5, len);
	ft_printf("\nSorted:\n");
	test_is_5(arr5, len);
	ft_printf("\nLight start mixed:\n");
	test_is_5(str_arr5, len);
	ft_printf("\nLight end mixed:\n");
	test_is_5(end_arr5, len);

	ft_printf("\n");
	*/
}


void bs_test(void)
{
	/*
	int len = 10;
	
	int arr1[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr1[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_1:");
	ft_printf("\n-----------------------\n");
	test_bs_1(arr1, len);
	test_bs_1(rev_arr1, len);
	test_bs_1(arr1, len);
	test_bs_1(str_arr1, len);
	test_bs_1(end_arr1, len);


	int arr2[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4}; 
	int rev_arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr2[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_2:");
	ft_printf("\n-----------------------\n");
	test_bs_2(arr2, len);
	test_bs_2(rev_arr2, len);
	test_bs_2(arr2, len);
	test_bs_2(str_arr2, len);
	test_bs_2(end_arr2, len);


	int arr3[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr3[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr3[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_3:");
	ft_printf("\n-----------------------\n");
	test_bs_3(arr3, len);
	test_bs_3(rev_arr3, len);
	test_bs_3(arr3, len);
	test_bs_3(str_arr3, len);
	test_bs_3(end_arr3, len);


	int arr4[10] = {7, 2, 9, 0, 5, 3, 8, 1, 6, 4};
	int rev_arr4[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	str_arr4[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int	end_arr4[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
	
	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_4:");
	ft_printf("\n-----------------------\n");
	test_bs_4(arr4, len);
	test_bs_4(rev_arr4, len);
	test_bs_4(arr4, len);
	test_bs_4(str_arr4, len);
	test_bs_4(end_arr4, len);


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
	*/

	ft_printf("\n");
}
