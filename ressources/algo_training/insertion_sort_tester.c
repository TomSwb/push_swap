
#include "algo_training.h"

void test_is_1(int *arr, int len)
{
    int i;
    int insertions;
    
    insertions = 0;
    i = 0;
    ft_printf("\n");
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