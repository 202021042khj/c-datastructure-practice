#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 연결 리스트로 구현한 큐의 노드 */
typedef struct QueueNode {
    element data;
    struct QueueNode *link;
} QueueNode;

/* front는 맨 앞 노드, rear는 맨 뒤 노드를 가리킴, 비었을 때 둘 다 NULL */
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} LinkedQueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(LinkedQueueType *q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(LinkedQueueType *q) {
    return (q->front == NULL);
}

/* 뒤에 새 노드를 넣음 */
void enqueue(LinkedQueueType *q, element item) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        error("메모리를 할당할 수 없습니다");
    } else {
        temp->data = item;
        temp->link = NULL;
        if (is_empty(q)) {
            q->front = temp;
            q->rear = temp;
        } else {
            q->rear->link = temp;
            q->rear = temp;
        }
    }
}

/* 앞의 노드를 꺼내고 값을 반환 */
element dequeue(LinkedQueueType *q) {
    if (is_empty(q)) {
        error("큐 공백 에러");
    } else {
        QueueNode *temp = q->front;
        element item = temp->data;
        q->front = temp->link;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        return item;
    }
}

element peek(LinkedQueueType *q) {
    if (is_empty(q)) {
        error("큐 공백 에러");
    } else {
        return q->front->data;
    }
}

int main(void) {
    LinkedQueueType q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("peek: %d\n", peek(&q));      /* 1 */
    printf("dequeue: %d\n", dequeue(&q)); /* 1 */
    printf("dequeue: %d\n", dequeue(&q)); /* 2 */

    return 0;
}
