
#include "../algo_training.h"

void	merge_sort_1(int *arr, int len)
{
	int	dest;
	int	*temp;

	if (len <= 1)
		return ;
	merge_sort_1(arr, len / 2);
	merge_sort_1(arr + len / 2, len - len / 2);
	temp = sort_temp(arr, len, 0, len / 2);
	dest = 0;
	while (dest < len)
	{
		arr[dest] = temp[dest];
		dest++;
	}
	free(temp);
}

int	*sort_temp(int *arr, int len, int left, int right)
{
	int	*temp;
	int	dest;

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
