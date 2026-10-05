
#include "../algo_training.h"

void selection_sort_1(int *arr, int len, int *selections)
{
    int i;
    int pos;
    int temp;
    
    pos = 0;
    while (pos < len - 1)
    {
        temp = arr[pos];
        i = pos + 1;
        while (i < len)
        {
            if (temp > arr[i])
                temp = arr[i];
            i++;
        }
        arr[pos] = temp;
        (*selections)++
        pos++;
    }
}