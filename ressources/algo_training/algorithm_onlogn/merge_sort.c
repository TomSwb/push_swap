
#include "../algo_training.h"

void merge_sort_1(int *arr, int len)
{
	int left;
	int right;
	int temp;
	
	if (!is_sorted(arr, len))
	{
		merge_sort_1(arr, len / 2);
		merge_sort_1(arr[len / 2], len / 2);
	}
	left = 0;
	right = len / 2;
	if (len <= 0)
		len = 1;
	while (left < len / 2)
	{
		if (arr[left] > arr[right])
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		if (right < len)
			right++;
		else
		{
			left++;
			right = len / 2;
		}
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
