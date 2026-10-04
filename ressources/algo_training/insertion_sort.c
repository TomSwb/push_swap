
#include "algo_training.h"

void insertion_sort_2(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int last;
    int temp;
    int insertion;
    
    insertion = 0;
    i = 0;
    next = 1;
    while (next < len)
    {
        while (next < len && arr[i] < arr[next])
            next++;
        if (arr[i] < arr[next])
        {
            temp = arr[next];
            last = next;
            while (next > i + 1 && arr[i] < arr[next])
            {
                arr[next - 1] = arr[next];
                next--;
            }
            arr[i] = temp;
            insertion++;
            i = next;
            next = last;
        }
        if (insertion > 0)
            (*insertions)++;
    }
}

void insertion_sort_1(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int temp;
    int insertion;
    
    i = 1;
    while (i < len - 1)
    {
        insertion = 0;
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