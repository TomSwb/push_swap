


// 3rd try 2nd optimization
void bubble_sort_3(int *arr, int len)
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
void bubble_sort_2(int *arr, int len)
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
// sequencing is n * n * n etc... until passing n times
// passes n times doing n operstions every time
void bubble_sort_1(int *arr, int len, int *efficiency)
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
        (*efficiency)++;
    }
}

/*
// stack version
void bubble_sort_stack(t_stack **stack)
{
    t_stack *head;
    
    head = *stack;
    while (head->next != *stack->next)
        head = head->next;
}
*/
