
#include "../algo_training.h"

void shell_sort_1(int *arr, int len)
{
    int i;
    int div;
    int temp;
    
    i = 0;
    div = 2;
    while (i < len - 1)
    {
        // looking forward loop
        while (len / div < len)
        {
            if (arr[i] > arr[len / div])
            {
                // bringing back loop
                while (i => 0 && arr[i] > arr[len / div])
                {
                    temp = arr[i];
                    arr[i] = arr[len / div];
                    arr[len / div] = temp;
                    i -= (len / div)
                }
                i = 0;
            }
            else
                i++;
        }
        if (div < len)
            div *= 2;
        else
            div = len;
        i++;
    }
}