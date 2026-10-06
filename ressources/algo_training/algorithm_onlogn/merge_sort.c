
#include "../algo_training.h"

void merge_sort_1(int *arr, int len)
{
	int left;
	int right;
	int dest;
	int *temp;
	
	if (len <= 1)
		return ;
	merge_sort_1(arr, len / 2);
	merge_sort_1(arr[len / 2], len / 2);
	temp = malloc(sizeof(int) * len);
	if (!temp)
		return ;
	left = 0;
	right = len / 2;
	dest = 0;
	while (left < len / 2 && right < len)
	{
		if (arr[left] < arr[right])
		{
			temp[dest] = arr[left];
			dest++;
			left++;
		}
		else
		{
			temp[dest] = arr[right];
			dest++;
			right++;
		}
	}
	while (left < len / 2)
	{
		temp[dest] = arr[left];
		dest++;
		left++;
	}
	while (right < len)
	{
		temp[dest] = arr[right];
		dest++;
		left++;
	}
	dest = 0;
	while (dest < len)
	{
		arr[dest] = temp[dest];
		dest++;
	}
	free(temp);
}
