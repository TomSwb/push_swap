
#include "algo_training.h"

void radix_sort(int *arr, int len)
{
    int iteration;
    
    interation = find_longest(int *arr, int len);




}

int find_longest(int *arr, int len)
{
    int max;
    int i;
    
    i = 0;
    max = 0;
    while (i < len)
    {
        if (arr[i] > max)
            max = arr[i];
        i++;
    }
    i = 0;
    while (max > 0)
    {
        max /= 10;
        i++;
    }
    return (i);
}