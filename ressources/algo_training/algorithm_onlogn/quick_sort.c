
#include "../algo_training.h"

void quick_sort_1(int *arr, int low, int high)
{
	int pivot;
    int i;
    int j;
    int temp;
    
    if (low >= high)
        return ;
    pivot = arr[low];
    i = low;
    j = low;
    while (j < high)
    {
        if (arr[j] < pivot)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
        j++;
    }
    temp = arr[high];
    arr[high] = arr[i];
    arr[i] = temp;
    quick_sort_1(arr, low, i - 1);
    quick_sort_1(arr, i + 1, high);
}
