
#include "../algo_training.h"

void quick_sort_1(int *arr, int len)
{
    int pivot;
    
    pivot = len - 1;
    
}

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
    
    
    arr = quick_sort_1(left, len);
    arr[] = pivot;
    quick_sort_1(right, len);
    
    
    i = 0;
    k = 0;
    while (i < j)
    {
        arr[i] = left[i]
        i++;
    }
    arr[i] = pivot;
    i++;
    while (i < len)
    {
        arr[i] = right[k];
        i++;
        k++;
    }
	free(left);
    free(right);
}

int *sort_temp(int *arr, int len, int left, int right)
{
	int *temp;
	int dest;
	
	dest = 0;
	temp = malloc(sizeof(int) * len);
	if (!temp)
		return (NULL);
	while (left < len / 2 && right < len)
	{
		if (arr[left] < arr[right])
			temp[dest++] = arr[left++];
		else
			temp[dest++] = arr[right++];
	}
	while (left < len / 2)
		temp[dest++] = arr[left++];
	while (right < len)
		temp[dest++] = arr[right++];
	return (temp);
}