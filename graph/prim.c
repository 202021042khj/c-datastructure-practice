#include <stdio.h>

#define V 5
#define INF 9999

/* 인접 행렬 가중치 그래프, 간선이 없으면 INF */
int graph[V][V] = {
    {0,   2,   INF, 6,   INF},
    {2,   0,   3,   8,   5  },
    {INF, 3,   0,   INF, 7  },
    {6,   8,   INF, 0,   9  },
    {INF, 5,   7,   9,   0  }
};

/* 프림: 트리에 속한 정점에서 갈 수 있는 가장 가벼운 간선을 계속 추가 */
int prim(int start) {
    int in_tree[V] = {0};
    int key[V];          /* 각 정점을 트리에 연결하는 최소 비용 */
    int parent[V];
    int total = 0;

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }
    key[start] = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!in_tree[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        in_tree[u] = 1;
        total += key[u];
        if (parent[u] != -1)
            printf("(%d, %d) w=%d\n", parent[u], u, graph[parent[u]][u]);

        for (int v = 0; v < V; v++) {
            if (!in_tree[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    return total;
}

int main(void) {
    printf("total: %d\n", prim(0));     /* 16 */
    return 0;
}
