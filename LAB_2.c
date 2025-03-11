107. Binary Tree Level Order Traversal II
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     in val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*)); 
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    int** result = (int**)malloc(2000 * sizeof(int*)); 
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));  
    *returnSize = 0;
    
    while (front < rear) {
        int levelSize = rear - front;
        int* level = (int*)malloc(levelSize * sizeof(int));
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            level[i] = node->val;
            
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
        
        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }
    
    result = (int**)realloc(result, (*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize / 2; i++) {
        int* temp = result[i];
        result[i] = result[*returnSize - i - 1];
        result[*returnSize - i - 1] = temp;
        
        int tempSize = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[*returnSize - i - 1];
        (*returnColumnSizes)[*returnSize - i - 1] = tempSize;
    }
    
    free(queue);
    
    return result;
}

