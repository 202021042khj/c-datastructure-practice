#include <stdio.h>

#define MAX_SIZE 10

/* 원형 큐: front와 rear가 같으면 빔, (rear + 1) % MAX_SIZE == front 이면 가득 참 */
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

int is_full(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Underflow\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Empty\n");
        return -1;
    }
    return q->data[(q->front + 1) % MAX_SIZE];
}

int main(void) {
    Queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("peek: %d\n", peek(&q));      /* 1 */
    printf("dequeue: %d\n", dequeue(&q)); /* 1 */
    printf("dequeue: %d\n", dequeue(&q)); /* 2 */

    return 0;
}
