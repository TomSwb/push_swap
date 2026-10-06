
#ifndef ALGO_TRAINING_H
# define ALGO_TRAINING_H

#include "./libft/libft.h"

// malloc(); free();
# include <unistd.h>

// on2_test.c
void slct_test(void);
void is_test(void);
void bs_test(void);

// onrootn_test.c
void shell_test(void);

// onlogn_test.c
void merge_test(void);

//---------------------------//

// ./algorithm_onlogn/..

// merge_sort.c
void merge_sort_1(int *arr, int len);
int *sort_temp(int *arr, int len, int left, int right);

// merge_sort_tester.c
void test_merge_1(int *arr, int len);

// ./algorithm_onrootn/..

// shell_sort.c
void shell_sort_1(int *arr, int len);
int	shell_manager(int *arr, int *i, int gap, int *swap_1);
int place_back_loop(int *arr, int *i, int gap);

// shell_sort_tester.c
void test_shell_1(int *arr, int len);

//---------------------------//

// ./algorithm_on2/..

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