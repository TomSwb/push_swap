
#include "../algo_training.h"

void selection_sort_2(int *arr, int len, int *selections, int *comparisons)
{
    int i;
    int pos;
    int lowest;
    int lowest_pos;
    int skip;
    
    skip = 1;
    pos = 0;
    while (pos < len - 1)
    {
        lowest = arr[pos];
        lowest_pos = pos;
        i = skip;
        skip = pos + 1;
        while (i < len)
        {
            if (find_lowest(arr, &i, &lowest, &lowest_pos, comparisons))
                skip = i - 1;
        }
        if (arr[pos] > arr[lowest_pos])
            place_lowest(arr, pos, lowest_pos, selections)
        pos++;
    }
}

int find_lowest(int *arr, int *i, int *lowest, int *lowest_pos, int *comparisons)
{
    int sorted
    
    sorted = 0;
    if (arr[*i] < arr[(*i) - 1]
        sorted = 1;
    (*comparisons)++;
    if (*lowest > arr[*i])
    {
        *lowest = arr[*i];
        *lowest_pos = *i;
    }
    (*i)++;
    return (sorted);
}

void place_lowest(int *arr, int pos, int lowest_pos, int *selections)
{
    int temp;
    
    temp = arr[pos];
    arr[pos] = arr[lowest_pos];
    arr[lowest_pos] = temp;
    (*selections)++;
}

void selection_sort_1(int *arr, int len, int *selections, int *comparisons)
{
    int i;
    int pos;
    int lowest;
    int lowest_pos;
    int temp;
    
    pos = 0;
    while (pos < len - 1)
    {
        lowest = arr[pos];
        lowest_pos = pos;
        i = pos + 1;
        while (i < len)
        {
			(*comparisons)++;
            if (lowest > arr[i])
            {
                lowest = arr[i];
                lowest_pos = i;
            }
            i++;
        }
		if (arr[pos] > arr[lowest_pos])
		{
			temp = arr[pos];
			arr[pos] = arr[lowest_pos];
			arr[lowest_pos] = temp;
			(*selections)++;
		}
        pos++;
    }
}