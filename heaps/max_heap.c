#include <stdio.h>

#define MAX_SIZE 100

/* 배열로 구현한 최대 힙: 1번 인덱스부터 사용, 부모는 i/2, 자식은 2i와 2i+1 */
typedef struct {
    int data[MAX_SIZE + 1];
    int size;
} MaxHeap;

void init_heap(MaxHeap *h) {
    h->size = 0;
}

int is_empty(MaxHeap *h) {
    return h->size == 0;
}

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert(MaxHeap *h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Overflow\n");
        return;
    }
    int i = ++(h->size);
    h->data[i] = value;

    /* 위로 올리며 부모보다 크면 교환 */
    while (i > 1 && h->data[i / 2] < h->data[i]) {
        swap(&h->data[i / 2], &h->data[i]);
        i /= 2;
    }
}

/* 루트 값을 꺼내고 힙 성질 복구 */
int delete_max(MaxHeap *h) {
    if (is_empty(h)) {
        printf("Empty\n");
        return -1;
    }
    int max = h->data[1];
    h->data[1] = h->data[h->size--];

    int i = 1;
    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= h->size && h->data[left] > h->data[largest])
            largest = left;
        if (right <= h->size && h->data[right] > h->data[largest])
            largest = right;
        if (largest == i)
            break;

        swap(&h->data[i], &h->data[largest]);
        i = largest;
    }
    return max;
}

int main(void) {
    MaxHeap h;
    init_heap(&h);

    int values[] = {5, 3, 8, 1, 9, 2};
    for (int i = 0; i < 6; i++)
        insert(&h, values[i]);

    printf("max: %d\n", delete_max(&h));   /* 9 */
    printf("max: %d\n", delete_max(&h));   /* 8 */
    printf("max: %d\n", delete_max(&h));   /* 5 */
    return 0;
}
