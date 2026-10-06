
#include "../algo_training.h"

void shell_sort_1(int *arr, int len)
{
	int	i;
	int	i_gap;
	int	div;
	int	temp;
	int swapped;

	i = 0;
	div = 2;
	while (i < len - 1)
	{
		if (len / div >= 1)
			i_gap = len / div;
		else
		 	i_gap = 1;
		swapped = 0;
		while ((i + i_gap) < len)
		{
			if (arr[i] > arr[i + i_gap])
			{
				// bringing back loop
				// place_back_loop(arr, &i, len, div)
				while (i >= 0 && arr[i] > arr[i + i_gap])
				{
					temp = arr[i];
					arr[i] = arr[i + i_gap];
					arr[i + i_gap] = temp;
					i -= i_gap;
					swapped += 1;
				}
				i = 0;
			}
			else
				i++;
		}
		ft_printf("%d\n", i_gap);
		div *= 2;
		if (swapped)
			i = 0;
		else
			i++;
	}
}

void place_back_loop(int *arr, int *i, int len, int div)
{
	int	temp;
	// bringing back loop
	while (*i >= 0 && arr[*i] > arr[len / div])
	{
		temp = arr[*i];
		arr[*i] = arr[len / div];
		arr[len / div] = temp;
		*i -= len / div;
	}
	*i = 0;
}
