#include <stdio.h>
#include <stdlib.h>

/* 연결 리스트로 구현한 큐: front에서 꺼내고 rear에 넣음 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

/* 성공하면 1 반환, 꺼낸 값은 *out에 저장 */
int dequeue(Queue *q, int *out) {
    if (is_empty(q)) {
        printf("Underflow\n");
        return 0;
    }
    Node *old = q->front;
    *out = old->data;
    q->front = old->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(old);
    return 1;
}

int main(void) {
    Queue q;
    int value;

    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    dequeue(&q, &value);
    printf("dequeue: %d\n", value);   /* 1 */
    dequeue(&q, &value);
    printf("dequeue: %d\n", value);   /* 2 */
    return 0;
}
