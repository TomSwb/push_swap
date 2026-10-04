
#ifndef ALGO_TRAINING_H
# define ALGO_TRAINING_H

#include "./libft/libft.h"

// main.c
void is_test(void);
void bs_test(void);

// insertion_sort.c
void insertion_sort_3(int *arr, int len, int *insertions);
void insertion_sort_2(int *arr, int len, int *insertions);
void insertion_sort_1(int *arr, int len, int *insertions);

// insertion_sort_tester.c
void test_is_3(int *arr, int len);
void test_is_2(int *arr, int len);
void test_is_1(int *arr, int len);

// bubble_sort.c
void bubble_sort_5(int *arr, int len, int *operations);
void left_right_swap(int *arr, int *i, int *last_swap, int *operations);
void right_left_swap(int *arr, int *i, int *last_swap, int *operations);

void bubble_sort_4(int *arr, int len, int *operations);
void bubble_sort_3(int *arr, int len, int *operations);
void bubble_sort_2(int *arr, int len, int *operations);
void bubble_sort_1(int *arr, int len, int *operations);

// bubble_sort_tester.c
void test_bs_1(int *arr, int len);
void test_bs_2(int *arr, int len);
void test_bs_3(int *arr, int len);
void test_bs_4(int *arr, int len);
void test_bs_5(int *arr, int len);

#endif