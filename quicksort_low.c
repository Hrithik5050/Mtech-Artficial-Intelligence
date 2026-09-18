#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        // Move i until we find an element >= pivot
        while (i <= high && arr[i] < pivot)
        {
            i++;
        }

        // Move j until we find an element <= pivot
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }

        // Swap arr[i] and arr[j]
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }

    // Put pivot in its correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}