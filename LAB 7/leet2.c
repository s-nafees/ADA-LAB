struct TreeNode* recoverFromPreorder(char* traversal) {
    if (traversal == NULL || traversal[0] == '\0') {
        return NULL;
    }

    // Stack to hold nodes during tree construction
    struct TreeNode* stack[1000];  // Assuming max depth doesn't exceed 1000
    int stackSize = 0;
    int i = 0;
    int n = strlen(traversal);

    // Helper function to create a new tree node
    struct TreeNode* createNode(int val) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    while (i < n) {
        int depth = 0;
        
        // Count the number of dashes to determine the depth of the node
        while (i < n && traversal[i] == '-') {
            depth++;
            i++;
        }
        
        // Parse the value of the node
        int val = 0;
        while (i < n && isdigit(traversal[i])) {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        // Create a new node with the parsed value
        struct TreeNode* node = createNode(val);

        // If the depth is equal to the stack size, the node is a child of the last node
        if (depth == stackSize) {
            // The current node will be the left child of the node at the top of the stack
            if (stackSize > 0 && stack[stackSize - 1]->left == NULL) {
                stack[stackSize - 1]->left = node;
            } else if (stackSize > 0) {
                stack[stackSize - 1]->right = node;
            }
        } else if (depth < stackSize) {
            // Pop nodes from the stack until the depth matches the correct level
            while (stackSize > depth) {
                stackSize--;
            }
            // The current node will be the right child of the node at the top of the stack
            if (stackSize > 0 && stack[stackSize - 1]->left == NULL) {
                stack[stackSize - 1]->left = node;
            } else if (stackSize > 0) {
                stack[stackSize - 1]->right = node;
            }
        }

        // Push the node onto the stack
        stack[stackSize++] = node;
    }

    // The root of the tree will always be the first element in the stack
    return stack[0];
}
