#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function prototypes
void displayMenu();
void inputData(int arr[], int *n);
void displayArray(int arr[], int n, char *label);
void bubbleSort(int arr[], int n);
void linearSearch(int arr[], int n, int target);
int recursiveBinarySearch(int arr[], int left, int right, int target, int depth);
void displaySearchResult(int found, int target, int index, int comparisons, char *algorithm);
void saveToFile(int arr[], int n, char *filename);
void loadFromFile(int arr[], int *n, char *filename);
void clearInputBuffer();

int main() {
    int data[MAX_SIZE];
    int sortedData[MAX_SIZE];
    int n = 0;
    int choice, target, result;
    char filename[50];
    
    printf("\n╔══════════════════════════════════════════════════════════════╗");
    printf("\n║             DATAVILLE RESEARCH CENTER                       ║");
    printf("\n║             Data Processing Tool v1.0                       ║");
    printf("\n╚══════════════════════════════════════════════════════════════╝\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (1-8): ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                inputData(data, &n);
                // Copy to sorted array for sorting
                for(int i = 0; i < n; i++) {
                    sortedData[i] = data[i];
                }
                break;
                
            case 2:
                if(n == 0) {
                    printf("\n⚠️  No data available! Please input data first.\n");
                    break;
                }
                displayArray(data, n, "Original Data");
                displayArray(sortedData, n, "Sorted Data");
                break;
                
            case 3:
                if(n == 0) {
                    printf("\n⚠️  No data available! Please input data first.\n");
                    break;
                }
                printf("\n══════════════════════════════════════════════════════\n");
                printf("               BUBBLE SORT ALGORITHM                  \n");
                printf("══════════════════════════════════════════════════════\n");
                
                // Make a copy for sorting display
                int sortCopy[MAX_SIZE];
                for(int i = 0; i < n; i++) {
                    sortCopy[i] = data[i];
                }
                
                bubbleSort(sortCopy, n);
                
                // Update sorted array
                for(int i = 0; i < n; i++) {
                    sortedData[i] = sortCopy[i];
                }
                
                printf("\n✓ Sorting completed successfully!\n");
                break;
                
            case 4:
                if(n == 0) {
                    printf("\n⚠️  No data available! Please input data first.\n");
                    break;
                }
                printf("\nEnter the number to search for: ");
                scanf("%d", &target);
                clearInputBuffer();
                
                printf("\n══════════════════════════════════════════════════════\n");
                printf("               LINEAR SEARCH                          \n");
                printf("══════════════════════════════════════════════════════\n");
                
                linearSearch(data, n, target);
                break;
                
            case 5:
                if(n == 0) {
                    printf("\n⚠️  No data available! Please input data first.\n");
                    break;
                }
                
                // Check if array is sorted for binary search
                bool isSorted = true;
                for(int i = 0; i < n - 1; i++) {
                    if(sortedData[i] > sortedData[i + 1]) {
                        isSorted = false;
                        break;
                    }
                }
                
                if(!isSorted) {
                    printf("\n⚠️  Array must be sorted for binary search!\n");
                    printf("Please use option 3 to sort the data first.\n");
                    break;
                }
                
                printf("\nEnter the number to search for: ");
                scanf("%d", &target);
                clearInputBuffer();
                
                printf("\n══════════════════════════════════════════════════════\n");
                printf("           RECURSIVE BINARY SEARCH                   \n");
                printf("══════════════════════════════════════════════════════\n");
                printf("\nSearching for %d in sorted array...\n\n", target);
                
                printf("Recursive call trace:\n");
                printf("──────────────────────\n");
                result = recursiveBinarySearch(sortedData, 0, n - 1, target, 0);
                
                if(result != -1) {
                    printf("\n✓ Found %d at index %d in the sorted array.\n", target, result);
                } else {
                    printf("\n✗ %d not found in the sorted array.\n", target);
                }
                break;
                
            case 6:
                if(n == 0) {
                    printf("\n⚠️  No data available! Please input data first.\n");
                    break;
                }
                printf("\nEnter filename to save data (e.g., data.txt): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                saveToFile(sortedData, n, filename);
                break;
                
            case 7:
                printf("\nEnter filename to load data from: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                loadFromFile(data, &n, filename);
                // Copy to sorted array
                for(int i = 0; i < n; i++) {
                    sortedData[i] = data[i];
                }
                break;
                
            case 8:
                printf("\n══════════════════════════════════════════════════════\n");
                printf("  Thank you for using DataVille Data Processing Tool!\n");
                printf("  Scientific research continues to thrive...\n");
                printf("══════════════════════════════════════════════════════\n");
                break;
                
            default:
                printf("\n❌ Invalid choice! Please enter a number between 1 and 8.\n");
        }
        
        if(choice != 8) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while(choice != 8);
    
    return 0;
}

void displayMenu() {
    printf("\n┌──────────────────────────────────────────────────────┐");
    printf("\n│                    MAIN MENU                         │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│  1. Input new data                                   │");
    printf("\n│  2. Display current data                             │");
    printf("\n│  3. Sort data (Bubble Sort)                          │");
    printf("\n│  4. Search data (Linear Search)                      │");
    printf("\n│  5. Search data (Recursive Binary Search)            │");
    printf("\n│  6. Save sorted data to file                         │");
    printf("\n│  7. Load data from file                              │");
    printf("\n│  8. Exit                                             │");
    printf("\n└──────────────────────────────────────────────────────┘\n");
}

void inputData(int arr[], int *n) {
    printf("\n══════════════════════════════════════════════════════\n");
    printf("                 INPUT DATA                           \n");
    printf("══════════════════════════════════════════════════════\n");
    
    printf("\nEnter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", n);
    clearInputBuffer();
    
    if(*n > MAX_SIZE || *n <= 0) {
        printf("❌ Invalid number of elements!\n");
        *n = 0;
        return;
    }
    
    printf("\nEnter %d integers (separated by spaces or newlines):\n", *n);
    for(int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
    clearInputBuffer();
    
    printf("\n✓ Data successfully recorded!\n");
}

void displayArray(int arr[], int n, char *label) {
    printf("\n%s:\n", label);
    printf("┌");
    for(int i = 0; i < n * 6 + 1; i++) printf("─");
    printf("┐\n│");
    
    for(int i = 0; i < n; i++) {
        printf(" %3d │", arr[i]);
    }
    
    printf("\n└");
    for(int i = 0; i < n * 6 + 1; i++) printf("─");
    printf("┘\n");
    
    printf("Indices: ");
    for(int i = 0; i < n; i++) {
        printf("%3d  ", i);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int temp, comparisons = 0, swaps = 0;
    bool swapped;
    
    printf("\nInitial array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        printf("\n〰️  Pass %d:\n", i + 1);
        
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;
            printf("  Comparing arr[%d]=%d and arr[%d]=%d", 
                   j, arr[j], j + 1, arr[j + 1]);
            
            if(arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                swaps++;
                
                printf(" → SWAP! ");
            } else {
                printf(" → no swap ");
            }
            
            // Display current state
            printf("[");
            for(int k = 0; k < n; k++) {
                if(k == j || k == j + 1) {
                    printf("{%d}", arr[k]);
                } else {
                    printf(" %d ", arr[k]);
                }
            }
            printf("]\n");
        }
        
        if(!swapped) {
            printf("\n✓ Array is already sorted! Early termination.\n");
            break;
        }
        
        printf("After pass %d: ", i + 1);
        for(int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
    
    printf("\n══════════════════════════════════════════════════════\n");
    printf("Sorting completed!\n");
    printf("Total comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);
    printf("Final sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n══════════════════════════════════════════════════════\n");
}

void linearSearch(int arr[], int n, int target) {
    int comparisons = 0;
    bool found = false;
    int foundIndex = -1;
    
    printf("\nSearching for %d using Linear Search:\n", target);
    printf("┌──────────────────────────────────────────────────────┐\n");
    
    for(int i = 0; i < n; i++) {
        comparisons++;
        printf("│ Step %2d: Check index %2d → value = %3d", 
               comparisons, i, arr[i]);
        
        if(arr[i] == target) {
            printf(" → FOUND! ✓\n");
            found = true;
            foundIndex = i;
            // Don't break to show we can find all occurrences
        } else {
            printf(" → not found\n");
        }
    }
    
    printf("└──────────────────────────────────────────────────────┘\n");
    
    if(found) {
        printf("\n✓ Target %d found at index %d\n", target, foundIndex);
    } else {
        printf("\n✗ Target %d not found in the array\n", target);
    }
    printf("Total comparisons: %d\n", comparisons);
}

int recursiveBinarySearch(int arr[], int left, int right, int target, int depth) {
    // Indentation for recursive call visualization
    for(int i = 0; i < depth; i++) printf("  ");
    
    if(left > right) {
        printf("recursiveBinarySearch(arr, %d, %d, %d) → NOT FOUND\n", 
               left, right, target);
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    printf("recursiveBinarySearch(arr, %d, %d, %d)\n", left, right, target);
    for(int i = 0; i < depth; i++) printf("  ");
    printf("  → mid = %d, arr[%d] = %d\n", mid, mid, arr[mid]);
    
    if(arr[mid] == target) {
        for(int i = 0; i < depth; i++) printf("  ");
        printf("  → MATCH FOUND! Returning index %d\n", mid);
        return mid;
    } else if(arr[mid] > target) {
        for(int i = 0; i < depth; i++) printf("  ");
        printf("  → %d > %d, searching LEFT half [%d..%d]\n", 
               arr[mid], target, left, mid - 1);
        return recursiveBinarySearch(arr, left, mid - 1, target, depth + 1);
    } else {
        for(int i = 0; i < depth; i++) printf("  ");
        printf("  → %d < %d, searching RIGHT half [%d..%d]\n", 
               arr[mid], target, mid + 1, right);
        return recursiveBinarySearch(arr, mid + 1, right, target, depth + 1);
    }
}

void saveToFile(int arr[], int n, char *filename) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("❌ Error opening file for writing!\n");
        return;
    }
    
    fprintf(file, "# DataVille Research Center - Sorted Data\n");
    fprintf(file, "# Total elements: %d\n", n);
    fprintf(file, "# Sorted using Bubble Sort\n\n");
    
    for(int i = 0; i < n; i++) {
        fprintf(file, "%d", arr[i]);
        if(i < n - 1) fprintf(file, " ");
        if((i + 1) % 10 == 0) fprintf(file, "\n");
    }
    
    fclose(file);
    printf("\n✓ Data successfully saved to '%s'\n", filename);
}

void loadFromFile(int arr[], int *n, char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("❌ Error opening file '%s'!\n", filename);
        return;
    }
    
    *n = 0;
    char line[256];
    int value;
    
    // Skip comment lines
    while(fgets(line, sizeof(line), file)) {
        if(line[0] != '#') {
            // Parse numbers from line
            char *token = strtok(line, " \t\n");
            while(token != NULL && *n < MAX_SIZE) {
                if(sscanf(token, "%d", &value) == 1) {
                    arr[(*n)++] = value;
                }
                token = strtok(NULL, " \t\n");
            }
        }
    }
    
    fclose(file);
    printf("\n✓ Loaded %d elements from '%s'\n", *n, filename);
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
