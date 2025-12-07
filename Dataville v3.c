#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSorted = false;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    printf("\n[DataVille Dataset]: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    isSorted = true;
    printf("\n>> System Message: Data successfully sorted using Optimized Bubble Sort.\n");
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearchRecursive(arr, low, mid - 1, target);

        return binarySearchRecursive(arr, mid + 1, high, target);
    }
    return -1;
}

int main() {
    int *data = NULL;
    int n = 0;
    int choice, target, result;

    printf("==========================================\n");
    printf("   DATAVILLE RESEARCH CENTER SYSTEM       \n");
    printf("   Algorithm Support Team Alpha           \n");
    printf("==========================================\n");

    printf("Enter the number of data elements to process: ");
    scanf("%d", &n);

    data = (int*)malloc(n * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers (space-separated): ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. View Data\n");
        printf("2. Sort Data (Bubble Sort)\n");
        printf("3. Search Data (Linear Search)\n");
        printf("4. Search Data (Recursive Binary Search)\n");
        printf("5. Exit System\n");
        printf("Select option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printArray(data, n);
                break;
            case 2:
                bubbleSort(data, n);
                printArray(data, n);
                break;
            case 3:
                printf("Enter value to search (Linear): ");
                scanf("%d", &target);
                result = linearSearch(data, n, target);
                if (result != -1)
                    printf(">> Found at index: %d\n", result);
                else
                    printf(">> Data not found.\n");
                break;
            case 4:
                if (!isSorted) {
                    printf(">> ERROR: Binary Search requires sorted data. Please choose Option 2 first.\n");
                } else {
                    printf("Enter value to search (Binary Recursive): ");
                    scanf("%d", &target);
                    result = binarySearchRecursive(data, 0, n - 1, target);
                    if (result != -1)
                        printf(">> Found at index: %d\n", result);
                    else
                        printf(">> Data not found.\n");
                }
                break;
            case 5:
                printf("Exiting DataVille System. Have a good day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    free(data);
    
    return 0;
}
