
#include "../algo_training.h"

void merge_sort_1(int *arr, int len)
{
	int i;
	int temp;
	
	if (!is_sorted(arr, len))
	{
		merge_sort_1(arr, len / 2);
		merge_sort_1(arr[len / 2], len / 2);
	}
	i = 0;
	if (len <= 0)
		len = 1;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		i++;
	}
}

int is_sorted(int *arr, int len)
{
	int i;
	
	i = 0;
	if (len <= 1)
		return (1);
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}