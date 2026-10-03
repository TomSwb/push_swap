
#include "algo_training.h"

int main(void)
{
    int arr1[10] = {7, 6, 2, 4, 9, 1, 3, 0, 5, 8};
    int arr2[10] = {7, 6, 2, 4, 9, 1, 3, 0, 5, 8};
	int arr3[10] = {7, 6, 2, 4, 9, 1, 3, 0, 5, 8};
	
	int rev_arr1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int rev_arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int rev_arr3[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	
	int len = 10;
    
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_1:");
	ft_printf("\n-----------------------\n");
    test_bs_1(arr1, len);
	test_bs_1(rev_arr1, len);
	test_bs_1(arr1, len);
	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_2:");
	ft_printf("\n-----------------------\n");
    test_bs_2(arr2, len);
	test_bs_2(rev_arr2, len);
	test_bs_2(arr2, len);
	ft_printf("\n");
	ft_printf("\n-----------------------\n");
	ft_printf("Testing bs_3:");
	ft_printf("\n-----------------------\n");
    test_bs_3(arr3, len);
	test_bs_3(rev_arr3, len);
	test_bs_3(arr3, len);
	ft_printf("\n");
}