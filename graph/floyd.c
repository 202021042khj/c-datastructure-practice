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

/* 플로이드: 경유 정점 k를 하나씩 늘려가며 모든 쌍의 최단 거리를 갱신 */
void floyd(int dist[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main(void) {
    int dist[V][V];
    floyd(dist);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%4d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
