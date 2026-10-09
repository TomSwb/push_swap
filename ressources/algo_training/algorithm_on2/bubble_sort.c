/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:55:48 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:47:35 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algo_training.h"

// 4th try 3rd optimization
void bubble_sort(int *arr, int len, int *operations)
{
	int	i;
	int	temp;
	int	boundary;
	int	last_swap;

	last_swap = 0;
	boundary = 0;
	while (boundary < len - 1 && last_swap >= 0)
	{
		last_swap = -1;
		i = 0;
		while (i < len - 1 - boundary)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				last_swap = i;
			}
			i++;
			(*operations)++;
		}
		if (last_swap >= 0)
			boundary = last_swap;
	}
}

/*
// 3rd try 2nd optimization
void bubble_sort_3(int *arr, int len, int *operations)
{
    int i;
    int temp;
    int pass;
    int swapped;
    
    swapped = 1;
    pass = 0;
    while (pass < len - 1 && swapped > 0)
    {
        swapped = 0;
        i = 0;
        while (i < len - 1 - pass)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
            i++;
            (*operations)++;
        }
        pass++;
    }
}


// 2nd try 1st optimization
// resets to i = 0 only once the highest 
// value reaches the end then next highest 
// reaches end - 1, etc...
// Sequencing is n * n-1 * n-2 etc until 0 which means passing n times
// same amount of passages but -1 ops every times
void bubble_sort_2(int *arr, int len, int *operations)
{
    int i;
    int temp;
    int pass;
    
    pass = 0;
    while (pass < len - 1)
    {
        i = 0;
        while (i < len - 1 - pass)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            i++;
            (*operations)++;
        }
        pass++;
    }
}

// 1st try
// resets to i = 0 everytime
// sequencing is n * n * n etc... until passing n times
// passes n times doing n operstions every time
void bubble_sort_1(int *arr, int len, int *operations)
{
    int i;
    int temp;
    
    i = 0;
    while (i < len - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = 0;
        }
        else
            i++;
        (*operations)++;
    }
}

*/
