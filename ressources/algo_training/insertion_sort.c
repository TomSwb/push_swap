
#include "algo_training.h"

void insertion_sort_2(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int temp;
    int insertion;
    
    insertion = 0;
    i = 1;
    while (i < len - 1)
    {
        while (i < len - 1 && arr[i] > arr[i - 1])
            i++;
        temp = arr[i];
        next = i;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[i] = temp;
        (*insertions)++;
        i = next;
    }
}

void insertion_sort_1(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int temp;
    int insertion;
    
    insertion = 0;
    i = 1;
    while (i < len - 1)
    {
        while (i < len - 1 && arr[i] > arr[i - 1])
            i++;
        next = i;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
            insertion++;
        }
        if (insertion > 0)
            (*insertions)++;
        i = next;
    }
}