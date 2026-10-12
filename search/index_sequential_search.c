#include <stdio.h>

#define BLOCK_SIZE 3

/* 색인 순차 탐색: 블록마다 첫 키를 색인 테이블에 저장하고,
 * 색인으로 블록을 찾은 뒤 그 블록 안에서 순차 탐색 */
typedef struct {
    int first_key;   /* 블록의 첫 키 */
    int start;       /* 블록의 시작 인덱스 */
} IndexEntry;

int index_search(int a[], int n, IndexEntry index[], int m, int key) {
    /* 1단계: 색인에서 key가 들어갈 블록 찾기 */
    int block = -1;
    for (int i = 0; i < m; i++) {
        if (index[i].first_key <= key)
            block = i;
        else
            break;
    }
    if (block == -1)
        return -1;

    /* 2단계: 블록 안에서 순차 탐색 */
    int end = (block + 1 < m) ? index[block + 1].start : n;
    for (int i = index[block].start; i < end; i++) {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main(void) {
    int a[] = {2, 5, 8, 12, 15, 20, 27, 31, 40};
    int n = sizeof(a) / sizeof(a[0]);

    /* 색인 테이블 만들기: BLOCK_SIZE 간격으로 */
    IndexEntry index[10];
    int m = 0;
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        index[m].first_key = a[i];
        index[m].start = i;
        m++;
    }

    printf("index of 15: %d\n", index_search(a, n, index, m, 15));  /* 4 */
    printf("index of 27: %d\n", index_search(a, n, index, m, 27));  /* 6 */
    printf("index of 9: %d\n", index_search(a, n, index, m, 9));    /* -1 */
    return 0;
}
