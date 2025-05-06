#include <stdio.h>

int n, m, w[10], p[10], v[10][10];

void knapsack(int, int, int[], int[]);
int max(int, int);

int main()
{
    int i, j;

    printf("Enter the no. of items: ");
    scanf("%d", &n);
    
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &m);
    
    printf("Enter weights: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("Enter profits: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    knapsack(n, m, w, p);
    
    printf("Optimal Solution:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void knapsack(int n, int m, int w[], int p[])
{
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (w[i] > j) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], ((v[i - 1][j - w[i]]) + p[i]));
            }
        }
    }
}

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

==OUTPUT==
Enter the no. of items:4
Enter the capacity of knapsack:5
Enter weights:2 1 3 2
Enter profits:12 10 20 15
Optimal Solution:
0 0 0 0 
0 10 10 10 
0 10 10 20 
0 10 15 25 
