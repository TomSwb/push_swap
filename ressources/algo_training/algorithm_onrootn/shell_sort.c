
#include "../algo_training.h"

void shell_sort_1(int *arr, int len)
{
    int i;
    int i_gap;
    int div;
    int temp;
    
    i = 0;
    div = 2;
    while (i < len - 1)
    {
        if (len > div)
            i_gap = len / div;
        else
            i_gap = 1;
        while (i_gap < len)
        {
            if (arr[i] > arr[i_gap])
            {
                // bringing back loop
                // place_back_loop(arr, &i, len, div)
                while (i >= 0 && arr[i] > arr[len / div])
                {
                    temp = arr[i];
                    arr[i] = arr[i_gap];
                    arr[i_gap] = temp;
                    i -= i_gap;
                    i_gap -= i_gap;
                }
                i = 0;
                if (len > div)
                    i_gap = len / div;
                else
                    i_gap = 1;
            }
            else
            {
                i++;
                i_gap++;
            }
        }
        if (div < len)
            div *= 2;
        else
            div = len;
        i++;
    }
}

void place_back_loop(int *arr, int *i, int len, int div)
{
    int temp;
    // bringing back loop
    while (*i >= 0 && arr[*i] > arr[len / div])
    {
        temp = arr[*i];
        arr[*i] = arr[len / div];
        arr[len / div] = temp;
        *i -= len / div;
    }
    *i = 0;
}
