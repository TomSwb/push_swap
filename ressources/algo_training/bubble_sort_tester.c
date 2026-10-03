
#include "algo_learning.h"

void test_bs_1(int *arr)
{
    int i = 0;
    int len = 10;
    
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
	ft_printf("\n");
    bubble_sort_1(arr, len);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
	ft_printf("\n");
}

void test_bs_2(int *arr)
{
    int i = 0;
    int len = 10;
    
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
	ft_printf("\n");
    bubble_sort_2(arr, len);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
	ft_printf("\n");
}

void test_bs_3(int *arr)
{
    int i = 0;
    int len = 10;
    
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
	ft_printf("\n");
    bubble_sort_3(arr, len);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
	ft_printf("\n");
}