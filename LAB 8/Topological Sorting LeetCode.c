#define MAX_COURSES 10000

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Adds a directed edge from 'from' to 'to' in the adjacency list
void addEdge(Node** graph, int from, int to) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = to;
    newNode->next = graph[from];
    graph[from] = newNode;
}

// Depth-First Search to detect cycles
int dfs(int course, int* visited, Node** graph) {
    if (visited[course] == 1) return 1;  // Cycle detected
    if (visited[course] == 2) return 0;  // Already visited, no cycle here

    visited[course] = 1;  // Mark as visiting
    Node* neighbor = graph[course];
    while (neighbor) {
        if (dfs(neighbor->val, visited, graph)) {
            return 1;  // Cycle found in recursive call
        }
        neighbor = neighbor->next;
    }

    visited[course] = 2;  // Mark as visited
    return 0;  // No cycle
}

// Main function to check if all courses can be finished
int canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    Node* graph[MAX_COURSES] = {0};         // Adjacency list for the graph
    int visited[MAX_COURSES] = {0};         // 0: unvisited, 1: visiting, 2: visited

    // Build the graph from prerequisites
    for (int i = 0; i < prerequisitesSize; i++) {
        int to = prerequisites[i][0];
        int from = prerequisites[i][1];
        addEdge(graph, from, to);
    }

    // Perform DFS on each course to check for cycles
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (dfs(i, visited, graph)) {
                return 0;  // Cycle detected, cannot finish all courses
            }
        }
    }

    return 1;  // No cycles found, all courses can be finished
}
OUTPUTS:
Input
numCourses =
2
prerequisites =
[[1,0]]
Output
true
Expected
true

Input
numCourses =
2
prerequisites =
[[1,0],[0,1]]
Output
false
Expected
false
