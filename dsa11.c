#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];      // Visited array
int queue[MAX], front = -1, rear = -1;
int nodes[MAX];        // Stores actual vertex values (like 35, 70, 105)
int nodeCount = 0;     // Keeps count of unique vertices

// Function to map vertex value to index
int getIndex(int val) {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] == val)
            return i;
    }
    nodes[nodeCount] = val;
    return nodeCount++;
}

// Enqueue
void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS Traversal
void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("BFS Traversal: ");
    visited[start] = 1;
    enqueue(start);

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", nodes[v]);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// DFS Traversal
void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", nodes[v]);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adj[i][j] = 0;

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        int ui = getIndex(u);
        int vi = getIndex(v);
        adj[ui][vi] = 1; // Directed edge
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);
    int startIndex = getIndex(start);

    // BFS
    front = rear = -1; // Reset queue
    BFS(startIndex, nodeCount);

    // DFS
    for (int i = 0; i < nodeCount; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(startIndex, nodeCount);
    printf("\n");

    return 0;
}
