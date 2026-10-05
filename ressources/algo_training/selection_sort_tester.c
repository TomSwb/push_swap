
#include "../algo_training.h"

void test_ss_1(int *arr, int len)
{
    int i;
    int selections;
    
    selections = 0;
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("%d\n", arr[i]);
    selection_sort_1(arr, len, &selections);
    i = 0;
    while (i < len - 1)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
	ft_printf("%d\n", arr[i]);
    ft_printf("Selections: %d\n", selections);
}