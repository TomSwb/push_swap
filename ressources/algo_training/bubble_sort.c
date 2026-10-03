
#include "./libft/libft.h"

void bubble_sort_int_arr(int **arr, int len);

int main(void)
{
    int arr[10] = {7, 6, 2, 4, 9, 1, 3, 0, 5, 8};
    int i = 0;
    int len = 10;
    
    ft_printf("\n");
    while (i < len)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("\n");
    bubble_sort_int_arr(arr, len);
    i = 0;
    while (i < len)
    {
        ft_printf("%d, ", arr[i]);
        i++;
    }
    ft_printf("\n");
}

void bubble_sort_int_arr(int *arr, int len)
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
        }
        pass++;
    }
}

void bubble_sort_stack(t_stack **stack)
{
    t_stack *head;
    
    head = *stack;
    while (head->next != *stack->next)
        head = head->next;
}
