/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_training.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:18:44 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:49:24 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_TRAINING_H
# define ALGO_TRAINING_H

//----------- Libraries ----------------//

// libft
# include "./libft/libft.h"

// malloc(); free();
# include <unistd.h>

//----------- Functions ----------------//

// onk_test.c
void	radix_test(void);

// onlogn_test.c
void	quick_test(void);
void	merge_test(void);

// on2_test.c
void	shell_test(void);
void	slct_test(void);
void	is_test(void);
void	css_test(void);
void	bs_test(void);

//---------- O(nk) ----------------//

// ./algorithm_onk/..

// Radix sort sorts the values one digit
// at a time, using a stable sorting method
// for each digit, until all digit positions
// have been processed.

// radix_sort.c
void	radix_sort(int *arr, int len);

// Counting sort counts how many values belong
// to each key, then uses those counts to place
// the values directly into their correct positions.

void	counting_sort(int *arr, int len, long it);
int		*create_count(int *arr, int len, long it);
void	temp_to_arr(int *arr, int *temp, int len);

long	find_longest(int *arr, int len);

void	radix_digit_sort(int *arr, int len);

// Digit sort groups values by a specific digit, 
// scanning the array for each possible digit 
// and keeping their original order within each group.

void	digit_sort( int *arr, int len, long it);

// radix_sort_tester.c
void	test_radix(int *arr, int len);

// void	test_radix_1(int *arr, int len);

//---------- O(n log n) ----------------//

// ./algorithm_onlogn/..

// Quick sort chooses a pivot and partitions
// the array so smaller values go to one side
// and larger values to the other, then recursively 
// sorts both sides.

// quick_sort.c
void	quick_sort(int *arr, int low, int high);
void	quick_loop(int *arr, int *i, int *j, int low);

// quick_sort_tester.c
void	test_quick(int *arr, int len);

// Merge sort recursively divides the array
// into smaller parts, then merges those parts
// back together in sorted order.

// merge_sort.c
void	merge_sort(int *arr, int len);
int		*sort_temp(int *arr, int len, int left, int right);

// merge_sort_tester.c
void	test_merge(int *arr, int len);

//---------- O(n2) --------------------//

// ./algorithm_on2/..

// Shell sort compares values separated
// by a decreasing gap, progressively
// reducing the gap until it becomes 1 and
// the array is fully sorted.

// shell_sort.c
void	shell_sort(int *arr, int len);
int		shell_manager(int *arr, int *i, int gap, int *swap_1);
int		place_back_loop(int *arr, int *i, int gap);

// shell_sort_tester.c
void	test_shell(int *arr, int len);

// Selection sort finds the smallest value
// in the unsorted part and swaps it into 
// the next position of the sorted part.

// selection_sort.c
void	selection_sort(int *arr, int len, int *selections, int *comparisons);
void	place_lowest(int *arr, int pos, int lowest_pos, int *selections);

// selection_sort_tester.c
void	test_slct(int *arr, int len);

// Insertion sort takes each value and inserts
// it into its correct position within the 
// already-sorted part by shifting larger values 
// to make space.

// insertion_sort.c
void	insertion_sort(int *arr, int len, int *insertions, int *comparisons, int *moves);
void	binary_insert(int i, int *arr, int *insertions, int *comparisons, int *moves);
int		binary_search(int i, int *arr, int temp, int *low, int *comparisons);

// insertion_sort_tester.c
void	test_is(int *arr, int len);

// Cocktail shaker sort applies bubble sort 
// in both directions, pushing the largest value 
// right and the smallest value left on each cycle.

// cocktail_shaker_sort.c
void	cocktail_shaker_sort(int *arr, int len, int *comparisons, int *swaps, int *moves);
void	left_right_swap(int *arr, int *i, int *last_swap, int *comparisons, int *swaps, int *moves);
void	right_left_swap(int *arr, int *i, int *last_swap, int *comparisons, int *swaps, int *moves);

// cocktail_shaker_sort_tester.c
void	test_css(int *arr, int len);

// Bubble sort compares adjacent values and 
// swaps them when they are in the wrong order, 
// repeatedly pushing the largest unsorted value 
// toward the right.

// bubble_sort.c
void	bubble_sort(int *arr, int len, int *operations);

// bubble_sort_tester.c
void	test_bs(int *arr, int len);

#endif