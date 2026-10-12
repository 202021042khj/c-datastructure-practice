#include <stdio.h>

#define N 6

/* 방향 그래프 (DAG): adj[i][j] = 1이면 i -> j */
int adj[N][N] = {
    {0, 1, 1, 0, 0, 0},   /* 0 -> 1, 2 */
    {0, 0, 0, 1, 0, 0},   /* 1 -> 3 */
    {0, 0, 0, 1, 0, 0},   /* 2 -> 3 */
    {0, 0, 0, 0, 1, 0},   /* 3 -> 4 */
    {0, 0, 0, 0, 0, 1},   /* 4 -> 5 */
    {0, 0, 0, 0, 0, 0}
};

/* 위상 정렬 (Kahn): 진입 차수가 0인 정점부터 꺼내며 간선 제거 */
void topological_sort(void) {
    int indegree[N] = {0};
    int queue[N];
    int front = 0, rear = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (adj[i][j])
                indegree[j]++;

    for (int i = 0; i < N; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int w = 0; w < N; w++) {
            if (adj[v][w]) {
                indegree[w]--;
                if (indegree[w] == 0)
                    queue[rear++] = w;
            }
        }
    }
    printf("\n");
}

int main(void) {
    topological_sort();     /* 0 1 2 3 4 5 */
    return 0;
}
