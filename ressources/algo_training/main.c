
#include "algo_training.h"

int main(void)
{
    int arr[10] = {7, 6, 2, 4, 9, 1, 3, 0, 5, 8};
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
    bubble_sort_int_arr(arr, len);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
	ft_printf("\n");
}