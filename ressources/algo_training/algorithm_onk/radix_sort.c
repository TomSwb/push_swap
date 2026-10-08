
#include "algo_training.h"

void radix_sort_2(int *arr, int len)
{
    long iteration;
    int it;
    
    iteration = find_longest(int *arr, int len);
    it = 1;
    while (it < iteration)
    {
        counting_sort(arr, len, it);
        it *= 10;
    }
}

void counting_sort( int *arr, int len, int it)
{
    int *count;
    int *temp;
    int i;
    int digit;
    
    count = create_count(arr, len, it);
    if (!count)
        return ;
    temp = malloc(sizeof(int) * len;
    if (!temp)
    {
        free(count);
        return ;
    }
    i = 0;
    while (i < len)
    {
        digit = (arr[i] / it) % 10
        temp[count[digit]] = arr[i];
        count[digit]++;
        i++;
    }
    temp_to_arr(arr, temp, len)
    free(temp);
    free(count);
}

int *create_count(int *arr, int len, int it)
{
    int *count;
    int i;
    int j;
    int digit;
    int index;
    
    count = ft_calloc(10, sizeof(int));
    if (!count)
        return (NULL);
    i = 0;
    while (i < len)
    {
        digit = (arr[i] / it) % 10;
        count[digit]++;
        i++;
    }
    i = 0;
    index = 0;
    while (i < 10)
    {
        j = count[i];
        count[i] = index;
        index += j;
        i++;
    }
    return (count);
}

void radix_sort_1(int *arr, int len)
{
    int iteration;
    int it;
    
    iteration = find_longest(int *arr, int len);
    it = 1;
    while (it < iteration)
    {
        digit_sort(arr, len, it);
        it *= 10;
    }
}

void digit_sort( int *arr, int len, int it)
{
    int *temp;
    int j;
    int i;
    
    temp = malloc(sizeof(int) * len)
    if (!temp)
        return ;
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
    temp_to_arr(arr, temp, len)
    free(temp);
}

long find_longest(int *arr, int len)
{
    long max;
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

void temp_to_arr(int *arr, int *temp, int len)
{
    int i;
    
    i = 0;
    while (i < len)
    {
        arr[i] = temp[i];
        i++;
    }
}
