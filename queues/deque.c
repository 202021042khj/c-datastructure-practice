#include <stdio.h>

#define MAX_SIZE 10

/* 원형 배열로 구현한 덱: 양쪽 끝에서 삽입과 삭제 가능
 * count로 비었는지, 가득 찼는지 구분 */
typedef struct {
    int data[MAX_SIZE];
    int front;
    int count;
} Deque;

void init_deque(Deque *d) {
    d->front = 0;
    d->count = 0;
}

int is_empty(Deque *d) {
    return d->count == 0;
}

int is_full(Deque *d) {
    return d->count == MAX_SIZE;
}

void push_front(Deque *d, int value) {
    if (is_full(d)) {
        printf("Overflow\n");
        return;
    }
    d->front = (d->front - 1 + MAX_SIZE) % MAX_SIZE;
    d->data[d->front] = value;
    d->count++;
}

void push_back(Deque *d, int value) {
    if (is_full(d)) {
        printf("Overflow\n");
        return;
    }
    d->data[(d->front + d->count) % MAX_SIZE] = value;
    d->count++;
}

/* 성공하면 1 반환, 꺼낸 값은 *out에 저장 */
int pop_front(Deque *d, int *out) {
    if (is_empty(d)) {
        printf("Underflow\n");
        return 0;
    }
    *out = d->data[d->front];
    d->front = (d->front + 1) % MAX_SIZE;
    d->count--;
    return 1;
}

int pop_back(Deque *d, int *out) {
    if (is_empty(d)) {
        printf("Underflow\n");
        return 0;
    }
    d->count--;
    *out = d->data[(d->front + d->count) % MAX_SIZE];
    return 1;
}

int main(void) {
    Deque d;
    int value;

    init_deque(&d);
    push_back(&d, 2);
    push_back(&d, 3);
    push_front(&d, 1);       /* 덱: 1 2 3 */

    pop_front(&d, &value);
    printf("front: %d\n", value);  /* 1 */
    pop_back(&d, &value);
    printf("back: %d\n", value);   /* 3 */
    return 0;
}
