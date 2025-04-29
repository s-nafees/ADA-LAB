#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

// Function to print the current permutation
void printPermutation(int* perm, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Function to find the index of the largest mobile integer
int getLargestMobile(int* perm, int* dir, int n) {
    int largest = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int moveTo = i + dir[i];
        if (moveTo >= 0 && moveTo < n && perm[i] > perm[moveTo]) {
            if (perm[i] > largest) {
                largest = perm[i];
                index = i;
            }
        }
    }
    return index;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void johnsonTrotter(int n) {
    int* perm = (int*)malloc(n * sizeof(int));
    int* dir = (int*)malloc(n * sizeof(int));

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int k = getLargestMobile(perm, dir, n);
        if (k == -1)
            break;

        int moveTo = k + dir[k];
        swap(&perm[k], &perm[moveTo]);
        swap(&dir[k], &dir[moveTo]);

        k = moveTo;
        int kVal = perm[k];

        // Reverse the direction of all elements greater than kVal
        for (int i = 0; i < n; i++) {
            if (perm[i] > kVal)
                dir[i] *= -1;
        }

        printPermutation(perm, n);
    }

    free(perm);
    free(dir);
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
