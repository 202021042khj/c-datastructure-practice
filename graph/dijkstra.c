#include <stdio.h>

#define V 5
#define INF 9999

int graph[V][V] = {
    {0,   2,   INF, 6,   INF},
    {2,   0,   3,   8,   5  },
    {INF, 3,   0,   INF, 7  },
    {6,   8,   INF, 0,   9  },
    {INF, 5,   7,   9,   0  }
};

/* 다익스트라: 아직 확정되지 않은 정점 중 거리가 가장 짧은 것을 골라 갱신 */
void dijkstra(int start, int dist[]) {
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[start] = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        if (dist[u] == INF)
            break;

        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}

int main(void) {
    int dist[V];
    dijkstra(0, dist);

    for (int i = 0; i < V; i++)
        printf("0 -> %d : %d\n", i, dist[i]);
    /* 0->0:0  0->1:2  0->2:5  0->3:6  0->4:7 */
    return 0;
}
