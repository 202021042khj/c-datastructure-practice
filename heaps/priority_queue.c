#include <stdio.h>

#define MAX_SIZE 100

/* 우선순위 큐: 최대 힙 구조로 구현. priority가 클수록 먼저 나옴 */
typedef struct {
    int priority;
    char name[20];
} Task;

typedef struct {
    Task data[MAX_SIZE + 1];
    int size;
} PriorityQueue;

void init_pq(PriorityQueue *pq) {
    pq->size = 0;
}

int is_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

static void swap(Task *a, Task *b) {
    Task tmp = *a;
    *a = *b;
    *b = tmp;
}

void enqueue(PriorityQueue *pq, Task t) {
    if (pq->size >= MAX_SIZE) {
        printf("Overflow\n");
        return;
    }
    int i = ++(pq->size);
    pq->data[i] = t;

    while (i > 1 && pq->data[i / 2].priority < pq->data[i].priority) {
        swap(&pq->data[i / 2], &pq->data[i]);
        i /= 2;
    }
}

/* 우선순위가 가장 높은 작업을 꺼냄 */
int dequeue(PriorityQueue *pq, Task *out) {
    if (is_empty(pq)) {
        printf("Empty\n");
        return 0;
    }
    *out = pq->data[1];
    pq->data[1] = pq->data[pq->size--];

    int i = 1;
    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= pq->size && pq->data[left].priority > pq->data[largest].priority)
            largest = left;
        if (right <= pq->size && pq->data[right].priority > pq->data[largest].priority)
            largest = right;
        if (largest == i)
            break;

        swap(&pq->data[i], &pq->data[largest]);
        i = largest;
    }
    return 1;
}

int main(void) {
    PriorityQueue pq;
    Task t;

    init_pq(&pq);
    Task a = {2, "write"};
    Task b = {5, "fix bug"};
    Task c = {1, "coffee"};
    enqueue(&pq, a);
    enqueue(&pq, b);
    enqueue(&pq, c);

    while (!is_empty(&pq)) {
        dequeue(&pq, &t);
        printf("%d %s\n", t.priority, t.name);
    }
    /* 5 fix bug / 2 write / 1 coffee */
    return 0;
}
