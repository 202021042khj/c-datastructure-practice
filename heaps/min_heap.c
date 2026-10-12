#include <stdio.h>

#define MAX_SIZE 100

/* 배열로 구현한 최소 힙: 1번 인덱스부터 사용 */
typedef struct {
    int data[MAX_SIZE + 1];
    int size;
} MinHeap;

void init_heap(MinHeap *h) {
    h->size = 0;
}

int is_empty(MinHeap *h) {
    return h->size == 0;
}

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert(MinHeap *h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Overflow\n");
        return;
    }
    int i = ++(h->size);
    h->data[i] = value;

    /* 위로 올리며 부모보다 작으면 교환 */
    while (i > 1 && h->data[i / 2] > h->data[i]) {
        swap(&h->data[i / 2], &h->data[i]);
        i /= 2;
    }
}

int delete_min(MinHeap *h) {
    if (is_empty(h)) {
        printf("Empty\n");
        return -1;
    }
    int min = h->data[1];
    h->data[1] = h->data[h->size--];

    int i = 1;
    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= h->size && h->data[left] < h->data[smallest])
            smallest = left;
        if (right <= h->size && h->data[right] < h->data[smallest])
            smallest = right;
        if (smallest == i)
            break;

        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return min;
}

int main(void) {
    MinHeap h;
    init_heap(&h);

    int values[] = {5, 3, 8, 1, 9, 2};
    for (int i = 0; i < 6; i++)
        insert(&h, values[i]);

    printf("min: %d\n", delete_min(&h));   /* 1 */
    printf("min: %d\n", delete_min(&h));   /* 2 */
    printf("min: %d\n", delete_min(&h));   /* 3 */
    return 0;
}
