
include "../algo_training.h"

void test_shell_1(int *arr, int len)
{
    int i;
    // int selections;
    // int comparisons;
    
    // selections = 0;
    // comparisons = 0;
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    shell_sort_1(arr, len);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    // ft_printf("Comparisons: %d\n", comparisons);
    // ft_printf("Selections: %d\n", selections);
    // ft_printf("Moves: %d\n", selections);
}
