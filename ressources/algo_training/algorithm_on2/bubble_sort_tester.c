
#include "../algo_training.h"

void test_bs_5(int *arr, int len)
{
    int i;
    int comparisons;
    int swaps;
    int moves;
    
    comparisons = 0;
    swaps = 0;
    moves = 0;
    i = 0;
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    bubble_sort_5(arr, len, &comparisons, &swaps, &moves);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Comparisons: %d\n", comparisons);
    ft_printf("Bubble Swaps: %d\n", swaps);
    ft_printf("Moves: %d\n", moves);
}
/*
void test_bs_4(int *arr, int len)
{
    int i;
    int operations;
    
    operations = 0;
    i = 0;
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    bubble_sort_4(arr, len, &operations);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Operations: %d\n", operations);
}

void test_bs_3(int *arr, int len)
{
    int i;
    int operations;
    
    operations = 0;
    i = 0;
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    bubble_sort_3(arr, len, &operations);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Operations: %d\n", operations);
}

void test_bs_2(int *arr, int len)
{
    int i;
    int operations;
    
    operations = 0;
    i = 0;
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    bubble_sort_2(arr, len, &operations);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Operations: %d\n", operations);
}

void test_bs_1(int *arr, int len)
{
    int i;
    int operations;
    
    operations = 0;
    i = 0;
    ft_printf("\n");
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    bubble_sort_1(arr, len, &operations);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Operations: %d\n", operations);
}
*/