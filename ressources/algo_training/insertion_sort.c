
#include "algo_training.h"

void insertion_sort_1(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int temp;
    
    i = 1;
    while (i < len)
    {
        while (i < len && arr[i] > arr[i - 1])
            i++;
        next = i;
        while (arr[i] < arr[i - 1])
        {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
        i = next;
        (*insertions)++;
    }
}