
#include "algo_training.h"

void insertion_sort_3(int *arr, int len, int *insertions)
{
    int i;
    int src;
    int block_len;
    int next;
    int temp;

    i = 0;
    while (i < len - 1)
    {
        block_len = 0;
        src = i;
        temp = arr[i];
        while (i < len - 1 && arr[i] > temp)
        {
            i++;
            block_len++;
        }
        temp = arr[i];
        next = i;
        memmove(&arr[src] + 1, &arr[src], sizeof(int) * block_len);
        if (i < len - 1)
            (*insertions)++;
        arr[i] = temp;
        i = next;
    }
}

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
        while (i > 0 && temp < arr[i - 1])
        {
            arr[i] = arr[i - 1];
            i--;
            insertion++;
        }
        arr[i] = temp;
        if (insertion > 0)
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