/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if (n == 1) {
        int* result = (int*)malloc(sizeof(int));
        result[0] = 0;
        *returnSize = 1;
        return result;
    }

    // Build graph
    int* degree = (int*)calloc(n, sizeof(int));
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        graph[i] = (int*)malloc(n * sizeof(int));  // Max possible connections: n-1
    }

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
        degree[u]++;
        degree[v]++;
    }

    // Queue for leaf nodes
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, back = 0;

    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            queue[back++] = i;
        }
    }

    int remainingNodes = n;

    while (remainingNodes > 2) {
        int layerSize = back - front;
        remainingNodes -= layerSize;

        for (int i = 0; i < layerSize; ++i) {
            int leaf = queue[front++];
            for (int j = 0; j < graphColSize[leaf]; ++j) {
                int neighbor = graph[leaf][j];
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    queue[back++] = neighbor;
                }
            }
        }
    }

    *returnSize = back - front;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; ++i) {
        result[i] = queue[front + i];
    }

    // Free memory
    for (int i = 0; i < n; ++i) {
        free(graph[i]);
    }
    free(graph);
    free(graphColSize);
    free(degree);
    free(queue);

    return result;
}
