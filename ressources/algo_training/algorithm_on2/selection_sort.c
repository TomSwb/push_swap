
#include "../algo_training.h"

void	selection_sort_1(int *arr, int len, int *selections, int *comparisons)
{
	int	i;
	int	pos;
	int	lowest;
	int	lowest_pos;

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
			place_lowest(arr, pos, lowest_pos, selections);
		pos++;
	}
}

void	place_lowest(int *arr, int pos, int lowest_pos, int *selections)
{
	int	temp;

	temp = arr[pos];
	arr[pos] = arr[lowest_pos];
	arr[lowest_pos] = temp;
	(*selections)++;
}
