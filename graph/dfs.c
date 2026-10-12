#include <stdio.h>

#define N 5

/* 인접 행렬로 표현한 무방향 그래프 (가중치 무시) */
int adj[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int visited[N];

/* 깊이 우선 탐색: 한 방향으로 끝까지 들어간 뒤 되돌아옴 */
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int w = 0; w < N; w++) {
        if (adj[v][w] && !visited[w])
            dfs(w);
    }
}

int main(void) {
    dfs(0);     /* 0 1 2 4 3 */
    printf("\n");
    return 0;
}
