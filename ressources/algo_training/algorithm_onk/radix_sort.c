
#include "algo_training.h"

void radix_sort(int *arr, int len)
{
    int iteration;
    int *temp;
    int it;
    int i;
    int j;
    int lsd;
    
    temp = malloc(sizeof(int) * len);
    if (!temp)
        return ;
    interation = find_longest(int *arr, int len);
    it = 1;
    while (it < iteration)
    {
        j = 0;
        lsd = 0;
        while (lsd < 10)
        {
            i = 0;
            while (i < len)
            {
                if ((arr[i] / it)) % 10 == lsd)
                {
                    temp[j] = arr[i];
                    j++;
                }
                i++;
            }
            lsd++;
        }
        it *= 10;
    }



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
    max = 1;
    while (i > 0)
    {
        max *= 10;
        i--;
    }
    return (max);
}