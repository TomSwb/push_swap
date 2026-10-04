
#include "algo_training.h"

void insertion_sort_1(int *arr, int len, int *operations)
{
    int i;
    int temp;
    
    i = 1;
    while (i < len)
    {
        if (arr[i] > arr[i - 1])
            i++;
        if (arr[i] < arr[i - 1])
        {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
        (*operations)++;
    }
}