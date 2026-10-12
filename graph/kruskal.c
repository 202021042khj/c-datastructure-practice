#include <stdio.h>

#define V 5
#define E 7

typedef struct {
    int u, v, w;
} Edge;

Edge edges[E] = {
    {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
    {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
};

int parent[V];

/* 분리 집합(Union-Find) */
int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void union_set(int a, int b) {
    parent[find(a)] = find(b);
}

/* 간선을 가중치 오름차순으로 정렬 (버블 정렬) */
void sort_edges(void) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - 1 - i; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
    }
}

/* 크루스칼: 가장 가벼운 간선부터 사이클이 생기지 않게 선택 */
int kruskal(void) {
    int total = 0, count = 0;

    sort_edges();
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (int i = 0; i < E && count < V - 1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            union_set(edges[i].u, edges[i].v);
            printf("(%d, %d) w=%d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
        }
    }
    return total;
}

int main(void) {
    printf("total: %d\n", kruskal());   /* 16 */
    return 0;
}
