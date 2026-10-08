
#ifndef ALGO_TRAINING_H
# define ALGO_TRAINING_H

//----------- Libraries ----------------//

// libft
#include "./libft/libft.h"

// malloc(); free();
# include <unistd.h>

//----------- Functions ----------------//

// onk_test.c
void radix_test(void);

// onlogn_test.c
void quick_test(void);
void merge_test(void);

// on2_test.c
void shell_test(void);
void slct_test(void);
void is_test(void);
void bs_test(void);

//---------- O(nk) ----------------//

// ./algorithm_onk/..

// radix_sort.c
void radix_sort_2(int *arr, int len);
void counting_sort(int *arr, int len, int it);
int *create_count(int *arr, int len, int it);

void radix_sort_1(int *arr, int len);
void digit_sort( int *arr, int len, int it);

long find_longest(int *arr, int len);
void temp_to_arr(int *arr, int *temp, int len);

// radix_sort_tester.c
void test_radix_2(int *arr, int len);
void test_radix_1(int *arr, int len);

//---------- O(n log n) ----------------//

// ./algorithm_onlogn/..

// quick_sort.c
void	quick_sort_1(int *arr, int low, int high);
void    quick_loop(int *arr, int *i, int *j, int low);

// quick_sort_tester.c
void test_quick_1(int *arr, int len);

// merge_sort.c
void merge_sort_1(int *arr, int len);
int *sort_temp(int *arr, int len, int left, int right);

// merge_sort_tester.c
void test_merge_1(int *arr, int len);

//---------- O(n2) --------------------//

// ./algorithm_on2/..

// shell_sort.c
void shell_sort_1(int *arr, int len);
int	shell_manager(int *arr, int *i, int gap, int *swap_1);
int place_back_loop(int *arr, int *i, int gap);

// shell_sort_tester.c
void test_shell_1(int *arr, int len);

// selection_sort.c
void selection_sort_1(int *arr, int len, int *selections, int *comparisons);
void place_lowest(int *arr, int pos, int lowest_pos, int *selections);

// selection_sort_tester.c
void test_slct_1(int *arr, int len);

// insertion_sort.c
void insertion_sort_4(int *arr, int len, int *insertions, int *comparisons, int* moves);
void binary_insert(int i, int *arr, int *insertions, int *comparisons, int *moves);
int binary_search(int i, int *arr, int temp, int *low, int *comparisons);

void insertion_sort_3(int *arr, int len, int *insertions);
void insertion_sort_2(int *arr, int len, int *insertions);
void insertion_sort_1(int *arr, int len, int *insertions);

// insertion_sort_tester.c
void test_is_4(int *arr, int len);
void test_is_3(int *arr, int len);
void test_is_2(int *arr, int len);
void test_is_1(int *arr, int len);

// bubble_sort.c
void bubble_sort_5(int *arr, int len, int *comparisons, int *swaps, int *moves);
void left_right_swap(int *arr, int *i, int *last_swap, int *comparisons, int *swaps, int *moves);
void right_left_swap(int *arr, int *i, int *last_swap, int *comparisons, int *swaps, int *moves);

void bubble_sort_4(int *arr, int len, int *operations);
void bubble_sort_3(int *arr, int len, int *operations);
void bubble_sort_2(int *arr, int len, int *operations);
void bubble_sort_1(int *arr, int len, int *operations);

// bubble_sort_tester.c
void test_bs_5(int *arr, int len);
void test_bs_4(int *arr, int len);
void test_bs_3(int *arr, int len);
void test_bs_2(int *arr, int len);
void test_bs_1(int *arr, int len);

#endif