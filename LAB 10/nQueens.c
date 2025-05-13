#include <stdio.h>
#include <stdbool.h>

bool place(int[], int);
void printSolution(int[], int);
void nQueens(int);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nQueens(n);
    return 0;
}

void nQueens(int n) {
    int x[10];
    int count = 0;
    int k = 1;
    while (k != 0) {
        x[k] = x[k] + 1;
        while (x[k] <= n && !place(x, k)) {
            x[k] = x[k] + 1;
        }
        if (x[k] <= n) {
            if (k == n) {
                count++;
                printf("Solution %d: ", count);
                printSolution(x, n);
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
    printf("Total solutions: %d\n", count);
}

bool place(int x[10], int k) {
    int i;
    for (i = 1; i < k; i++) {
        if ((x[i] == x[k]) || (i - x[i] == k - x[k]) || (i + x[i] == k + x[k])) {
            return false;
        }
    }
    return true;
}

void printSolution(int x[10], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("(%d, %d) ", i, x[i]);
    }
    printf("\n");
}

==OUTPUT==
Enter the number of queens: 4
Solution 1: (1, 2) (2, 4) (3, 1) (4, 3)
Solution 2: (1, 3) (2, 1) (3, 4) (4, 2)
Total solutions: 2
