
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
        if (arr[i] < arr[next])
            next++;
        if (arr[next] < arr[i])
        {
            temp = arr[next];
            last = next;
            while (next > i + 1)
            {
                arr[next] = arr[next - 1];
                next--;
            }
            arr[i] = temp;
            insertion++;
            i = last;
            next = last + 1;
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