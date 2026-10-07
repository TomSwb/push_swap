
#include "../algo_training.h"

void quick_sort_1(int *arr, int len)
{
	int pivot;
    int i;
    int j;
    int k;
	int *left;
    int *right
	
	if (len <= 1)
		return ;
    i = 0;
    j = 0;
    k = 0;
    left = malloc(sizeof(int) * len);
	if (!left)
		return (NULL);
    right = malloc(sizeof(int) * len);
	if (!right)
		return (NULL);
	pivot = arr[i]
    while (i < len - 1)
    {
        if (pivot < arr[i])
        {
            left[j] = arr[i]
            j++;
            i++;
        }
        else
        {
            right[k] = arr[i]
            k++;
            i++;
        }
    }
    i = 0;
    while (i < j)
    {
        arr[i] = left[i];
        i++;
    }
    arr[i] = pivot;
    i++;
    j = 0;
    while (i < len)
    {
        arr[i] = right[j];
        i++;
        j++;
    }
	free(left);
    free(right);
    return (arr);
}
