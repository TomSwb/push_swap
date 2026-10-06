
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
	free(temp);
}
