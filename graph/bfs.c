#include <stdio.h>

#define N 5

int adj[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

/* 너비 우선 탐색: 가까운 정점부터 큐로 탐색 */
void bfs(int start) {
    int visited[N] = {0};
    int queue[N];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int w = 0; w < N; w++) {
            if (adj[v][w] && !visited[w]) {
                visited[w] = 1;
                queue[rear++] = w;
            }
        }
    }
}

int main(void) {
    bfs(0);     /* 0 1 3 2 4 */
    printf("\n");
    return 0;
}
