/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:57:47 by atardy            #+#    #+#             */
/*   Updated: 2026/10/26 17:41:25 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// bucket sort with root n stack and only positive values

int	find_nxt_root(int nb)
{
	int	i;
	
    i = 1;
    while (i * i <= nb)
        i++;
    return (i);
}

void	bucket_merge(int **buckets, int *stack_a, int size)
{
	int	index;
	int	nb;
	int	position;

	index = -1;
	position = 0;
	while (++index < find_nxt_root(size))
	{
		nb = -1;
		while (buckets[index][++nb] != -1)
		{
			stack_a[position] = buckets[index][nb];
			position++;
		}
	}
}

void	bubble_sort(int	*array, int size)
{
	int	i;
	int	flag;
	int	temp; 

	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		i = -1;
		while (array[i + 1] != -1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
	}
}


void	bucket_dividing(int **buckets, int *stack_a, int size, int n_buckets)
{
	int	i;
	int	index;
	int	j;
	
	i = -1;
	while (++i < size)
	{
		index = stack_a[i] / n_buckets;
		j = 0;
		while (buckets[index][j] != -1)
			j++;
		buckets[index][j] = stack_a[i];
	}
}

int	*bucket_sort(int *stack_a, int size)
{
	int	i;
	int	**buckets;
	int	n_buc;
	int j;
	
	i = -1;
	n_buc = find_nxt_root(size);
	buckets = malloc(sizeof(int *) * (n_buc + 1));
	if (!buckets)
		return (NULL);
	buckets[n_buc] = 0;
	while (++i < n_buc)
	{
		buckets[i] = malloc (sizeof(int) * size);
		if (buckets[i] == NULL)
			return (NULL);
		j = -1;
		while (++j < size)
			buckets[i][j] = -1;
	}
	bucket_dividing(buckets, stack_a, size, n_buc);
// i = -1;
// while (++i < find_nxt_root(size))
// {
// 	printf("bucket[%d] : ", i);
// 	j = -1;
// 	while (buckets[i][++j] != -1)
// 		printf("%d, ", buckets[i][j]);
// 	printf("\n");
// }
	i = -1;
	while (++i < n_buc)
		bubble_sort(buckets[i], size);
	bucket_merge(buckets, stack_a, size);
	return (stack_a);
}

int	main(void)
{
	int nb[] = {3, 4, 12, 2, 1, 13, 7, 10, 0, 5, 6, 9, 8, 11};
	int	i;

	i = -1;
	bucket_sort(&nb[0], 14);
	while (++i < 14)
		printf("%d, ", nb[i]);
	return(0);
}