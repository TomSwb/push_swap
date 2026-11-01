/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:57:38 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:51:42 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo_training.h"

void	insertion_sort(int *arr, int len, int *insertions, int *comparisons, int *moves)
{
	int	i;

	i = 1;
	while (i < len)
	{
		while (i < len - 1)
		{
			if (arr[i] > arr[i - 1])
			{
				(*comparisons)++;
				i++;
			}
			else
				break ;
		}
		if (i < len)
			binary_insert(i, arr, insertions, comparisons, moves);
		i++;
	}
}

void	binary_insert(int i, int *arr, int *insertions, int *comparisons, int *moves)
{
	int	block_len;
	int	temp;
	int	low;

	block_len = 0;
	temp = arr[i];
	low = 0;
	block_len = binary_search(i, arr, temp, &low, comparisons);
	if (block_len > 0)
	{
		ft_memmove(&arr[low] + 1, &arr[low], sizeof(int) * block_len);
		(*moves) += block_len;
		arr[low] = temp;
		(*insertions)++;
	}
}

int	binary_search(int i, int *arr, int temp, int *low, int *comparisons)
{
	int	mid;
	int	high;

	high = i;
	while (*low < high)
	{
		mid = (*low) + (high - (*low)) / 2;
		(*comparisons)++;
		if (arr[mid] < temp)
			*low = mid + 1;
		else
			high = mid;
	}
	return (i - (*low));
}

/*
void insertion_sort_3(int *arr, int len, int *insertions)
{
    int i;
    int block_len;
    int next;
    int temp;

    i = 1;
    while (i < len)
    {
        block_len = 0;
        while (i < len - 1 && arr[i] > arr[i - 1])
            i++;
        if (i < len)
        {
            temp = arr[i];
            next = i;
            while (i > 0 && temp < arr[i - 1])
            {
                i--;
                block_len++;
            }
            if (block_len > 0)
            {
                ft_memmove(&arr[i] + 1, &arr[i], sizeof(int) * block_len);
                arr[i] = temp;
                (*insertions)++;
                i = next;
            }
            else
             i++;
        }
    }
}

void insertion_sort_2(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int temp;
    int insertion;
    
    insertion = 0;
    i = 1;
    while (i < len - 1)
    {
        while (i < len - 1 && arr[i] > arr[i - 1])
            i++;
        temp = arr[i];
        next = i;
        while (i > 0 && temp < arr[i - 1])
        {
            arr[i] = arr[i - 1];
            i--;
            insertion++;
        }
        arr[i] = temp;
        if (insertion > 0)
            (*insertions)++;
        i = next;
    }
}

void insertion_sort_1(int *arr, int len, int *insertions)
{
    int i;
    int next;
    int temp;
    int insertion;
    
    insertion = 0;
    i = 1;
    while (i < len - 1)
    {
        while (i < len - 1 && arr[i] > arr[i - 1])
            i++;
        next = i;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
            insertion++;
        }
        if (insertion > 0)
            (*insertions)++;
        i = next;
    }
}
*/