
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

// 3rd try 2nd optimization
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

/*
// 2nd try 1st optimization
// resets to i = 0 only once the highest 
value reaches the end then next highest 
reaches end - 1, etc...
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

// 1st try
// resets to i = 0 everytime
void bubble_sort_int_arr(int *arr, int len)
{
    int i;
    int temp;
    
    while (i < len - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = 0;
        }
        i++;
    }
}

// stack version
void bubble_sort_stack(t_stack **stack)
{
    t_stack *head;
    
    head = *stack;
    while (head->next != *stack->next)
        head = head->next;
}
*/
