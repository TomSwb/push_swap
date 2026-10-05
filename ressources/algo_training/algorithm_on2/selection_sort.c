
#include "../algo_training.h"

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