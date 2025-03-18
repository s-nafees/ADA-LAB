####QUICK SORT####
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // For time measurement

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

void quickSort(int arr[], int n) {
    qs(arr, 0, n - 1);
}

void inputSmallArray(int **arr, int *n) {
    printf("Enter the number of elements in the array: ");
    scanf("%d", n);

    *arr = (int *)malloc(*n * sizeof(int));  // Allocate memory dynamically for the array

    printf("\nEnter %d elements into the array:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void inputLargeRandomArray(int **arr, int *n) {
    printf("Enter the number of elements for the large array: ");
    scanf("%d", n);  // User defines the array size

    *arr = (int *)malloc(*n * sizeof(int));  // Allocate memory dynamically for the array

    for (int i = 0; i < *n; i++) {
        (*arr)[i] = rand() % 100000;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;  // Pointer to hold the dynamically allocated array
    int n;
    int choice;

    printf("Choose an option:\n");
    printf("1. Enter small array (manual input)\n");
    printf("2. Generate large random array (user-defined size)\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputSmallArray(&arr, &n);  // User inputs the array
            break;
        case 2:
            inputLargeRandomArray(&arr, &n);  // User defines the size of the random array
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }

    // If the user chooses the small array, print before and after sorting
    if (choice == 1) {
        printf("Before Sorting:\n");
        printArray(arr, n);  // Show the array before sorting
    }

    // Measure the time taken to sort the array
    clock_t startTime = clock();  // Start clock
    quickSort(arr, n);  // Perform quickSort
    clock_t endTime = clock();  // End clock

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;  // Calculate time taken in milliseconds
    printf("\nTime taken to sort %d elements: %f milliseconds\n", n, timeTaken);

    // If the user chooses the small array, print after sorting
    if (choice == 1) {
        printf("After Sorting:\n");
        printArray(arr, n);  // Show the array after sorting
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
== OUTPUT ==
Choose an option:
1. Enter small array (manual input)
2. Generate large random array (user-defined size)
1
Enter the number of elements in the array: 6

Enter 6 elements into the array:
3
4
7
7
5
3
Before Sorting:
3 4 7 7 5 3

Time taken to sort 6 elements: 0.000000 milliseconds
After Sorting:
3 3 4 5 7 7

Process returned 0 (0x0)   execution time : 14.816 s
Press any key to continue.
Choose an option:
1. Enter small array (manual input)
2. Generate large random array (user-defined size)
2
Enter the number of elements for the large array: 100000

Time taken to sort 100000 elements: 7.000000 milliseconds

Process returned 0 (0x0)   execution time : 2.920 s
Press any key to continue.
--------------------------------------------------------------------------------------------------------
####MERGE SORT####

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;

    int n1 = mid - low + 1;
    int n2 = high - mid;
    int b[n1], c[n2];

    for (int i = 0; i < n1; i++)
        b[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        c[j] = arr[mid + 1 + j];

    mergeSort(b, 0, n1 - 1);
    mergeSort(c, 0, n2 - 1);

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (b[i] <= c[j]) {
            arr[k] = b[i];
            i++;
        } else {
            arr[k] = c[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = b[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = c[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    printf("Choose an option:\n");
    printf("1. Small length (User input)\n");
    printf("2. Big length (Random numbers)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int arr[n];

        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        printf("Sorted array:\n");
        printArray(arr, n);
        printf("Time taken: %f Milli-seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

    } else if (choice == 2) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int));

        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        printf("Sorting completed.\n");
        printf("Time taken: %f Milli-seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

        free(arr);

    } else if (choice == 3) {
        printf("Exiting...\n");
        return 0;
    } else {
        printf("Invalid choice! Exiting...\n");
    }

    return 0;
}
==OUTPUT==
Choose an option:
1. Small length (User input)
2. Big length (Random numbers)
3. Exit
Enter your choice: 1
Enter the number of elements: 6
Enter 6 elements: 3
4
7
3
6
3
Sorted array:
3 3 3 4 6 7
Time taken: 0.000000 Milli-seconds

Process returned 0 (0x0)   execution time : 10.731 s
Press any key to continue.
Choose an option:
1. Small length (User input)
2. Big length (Random numbers)
3. Exit
Enter your choice: 2
Enter the number of elements: 100000
Sorting completed.
Time taken: 11.000000 Milli-seconds

Process returned 0 (0x0)   execution time : 5.876 s
Press any key to continue.
