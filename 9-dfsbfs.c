#include <stdio.h>

int graph[10][10];
int visited[10];
int n = 6;

// DFS
void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// BFS
void bfs(int start) {
    int queue[100];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    // Adjacency matrix (ornek)
    int adjMatrix[10][10] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    // graph'a kopyala
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = adjMatrix[i][j];
        }
    }

    // DFS icin visited sifirla
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS traversal: ");
    dfs(0);
    printf("\n");

    // BFS icin visited sifirla
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("BFS traversal: ");
    bfs(0);
    printf("\n");

    return 0;
}
