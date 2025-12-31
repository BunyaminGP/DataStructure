#include <stdio.h>

#define MAX 200

int graph[MAX][MAX];
int visited[MAX];

void clusterBulBFS(int n) {
    int queue[MAX];
    int clusterNo = 0;

    for (int start = 0; start < n; start++) {
        if (visited[start]) continue;

        // Yeni cluster bulundu
        clusterNo++;
        printf("Cluster %d: ", clusterNo);

        // BFS baslat
        int front = 0, rear = 0;
        queue[rear++] = start;
        visited[start] = 1;

        while (front < rear) {
            int u = queue[front++];
            printf("%d ", u);

            // u'nun komsularina bak
            for (int v = 0; v < n; v++) {
                if (graph[u][v] == 1 && !visited[v]) {
                    visited[v] = 1;
                    queue[rear++] = v;
                }
            }
        }

        printf("\n");
    }
}

int main() {
    int n;

    printf("Dugum sayisi (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Gecersiz N!\n");
        return 0;
    }

    printf("Adjacency matrix giriniz (0/1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // visited sifirla
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("\nClusterlar (Bagli bilesenler):\n");
    clusterBulBFS(n);

    return 0;
}
