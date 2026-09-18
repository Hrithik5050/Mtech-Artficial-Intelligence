#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    // Compare elements from both sorted parts
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left part
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right part
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp back into original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Divide left part
        mergeSort(arr, low, mid);

        // Divide right part
        mergeSort(arr, mid + 1, high);

        // Merge both parts
        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}