
#include "../algo_training.h"

void test_is_4(int *arr, int len)
{
    int i;
    int insertions;
    int comparisons;
    int moves;
    
    insertions = 0;
    comparisons = 0;
    moves = 0;
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    insertion_sort_4(arr, len, &insertions, &comparisons, &moves);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Comparisons: %d\n", comparisons);
    ft_printf("Insertions: %d\n", insertions);
    ft_printf("Moves: %d\n", moves);
}

void test_is_3(int *arr, int len)
{
    int i;
    int insertions;
    
    insertions = 0;
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    insertion_sort_3(arr, len, &insertions);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Insertions: %d\n", insertions);
}

void test_is_2(int *arr, int len)
{
    int i;
    int insertions;
    
    insertions = 0;
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    insertion_sort_2(arr, len, &insertions);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Insertions: %d\n", insertions);
}

void test_is_1(int *arr, int len)
{
    int i;
    int insertions;
    
    insertions = 0;
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    insertion_sort_1(arr, len, &insertions);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Insertions: %d\n", insertions);
}