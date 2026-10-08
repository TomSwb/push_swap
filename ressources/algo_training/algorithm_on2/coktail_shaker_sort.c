
#include "../algo_training.h"

void	cocktail_shaker_sort(int *arr, int len, int *comparisons, int *swaps, int *moves)
{
	int	i;
	int	start;
	int	end;
	int	last_swap;

	last_swap = 0;
	start = 0;
	end = len - 1;
	while (start < end && last_swap >= 0)
	{
		last_swap = -1;
		i = start;
		while (i < end)
			left_right_swap(arr, &i, &last_swap, comparisons, swaps, moves);
		if (last_swap >= 0)
			end = last_swap + 1;
		else if (last_swap == -1)
			break ;
		last_swap = -1;
		i = end;
		while (i > start)
			right_left_swap(arr, &i, &last_swap, comparisons, swaps, moves);
		if (last_swap >= 0)
			start = last_swap - 1;
	}
}

void	left_right_swap(int *arr, int *i, int *last_swap, int *comparisons, int *swaps, int *moves)
{
	int	temp;

	(*comparisons)++;
	if (arr[*i] > arr[(*i) + 1])
	{
		(*swaps)++;
		temp = arr[*i];
		arr[*i] = arr[(*i) + 1];
		arr[(*i) + 1] = temp;
		*last_swap = *i;
		(*moves) += 2;
	}
	(*i)++;
}

void	right_left_swap(int *arr, int *i, int *last_swap, int *comparisons, int *swaps, int *moves)
{
	int	temp;

	(*comparisons)++;
	if (arr[*i] < arr[(*i) - 1])
	{
		(*swaps)++;
		temp = arr[*i];
		arr[*i] = arr[(*i) - 1];
		arr[(*i) - 1] = temp;
		*last_swap = *i;
		(*moves) += 2;
	}
	(*i)--;
}
