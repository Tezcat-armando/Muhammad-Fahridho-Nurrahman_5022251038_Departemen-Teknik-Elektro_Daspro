#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearchRecursive(arr, left, mid - 1, target);
    else
        return binarySearchRecursive(arr, mid + 1, right, target);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], sorted[n];
    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];  // copy for sorting
    }

    int target;
    printf("Enter value to search for: ");
    scanf("%d", &target);

    printf("\nOriginal Data: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    // Linear search on unsorted
    int linear_unsorted = linearSearch(arr, n, target);
    printf("\nLinear Search (unsorted): %d", linear_unsorted);

    // Sort the data
    bubbleSort(sorted, n);

    printf("\n\nSorted Data: ");
    for (int i = 0; i < n; i++) printf("%d ", sorted[i]);

    // Linear search on sorted
    int linear_sorted = linearSearch(sorted, n, target);
    printf("\nLinear Search (sorted): %d", linear_sorted);

    // Recursive binary search
    int binary_index = binarySearchRecursive(sorted, 0, n - 1, target);
    printf("\nBinary Search (recursive): %d\n", binary_index);

    return 0;
}
