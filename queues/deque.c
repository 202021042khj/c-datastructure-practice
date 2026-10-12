#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 이중 연결 리스트로 구현한 덱의 노드 */
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

/* head는 맨 앞 노드, tail은 맨 뒤 노드, 비었을 때 둘 다 NULL */
typedef struct {
    DlistNode *head;
    DlistNode *tail;
} DequeType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

DlistNode *create_node(DlistNode *prev, element item, DlistNode *next) {
    DlistNode *new_node = (DlistNode *)malloc(sizeof(DlistNode));
    if (new_node == NULL) {
        error("메모리를 할당할 수 없습니다");
    } else {
        new_node->data = item;
        new_node->llink = prev;
        new_node->rlink = next;
    }
    return new_node;
}

void init_deque(DequeType *dq) {
    dq->head = NULL;
    dq->tail = NULL;
}

int is_empty(DequeType *dq) {
    return (dq->head == NULL);
}

/* 앞에 삽입 */
void add_front(DequeType *dq, element item) {
    DlistNode *new_node = create_node(NULL, item, dq->head);
    if (is_empty(dq)) {
        dq->tail = new_node;
    } else {
        dq->head->llink = new_node;
    }
    dq->head = new_node;
}

/* 뒤에 삽입 */
void add_rear(DequeType *dq, element item) {
    DlistNode *new_node = create_node(dq->tail, item, NULL);
    if (is_empty(dq)) {
        dq->head = new_node;
    } else {
        dq->tail->rlink = new_node;
    }
    dq->tail = new_node;
}

/* 앞 원소를 삭제하고 값을 반환 */
element delete_front(DequeType *dq) {
    if (is_empty(dq)) {
        error("덱 공백 에러");
    } else {
        DlistNode *removed = dq->head;
        element item = removed->data;
        dq->head = removed->rlink;
        if (dq->head == NULL)
            dq->tail = NULL;
        else
            dq->head->llink = NULL;
        free(removed);
        return item;
    }
}

/* 뒤 원소를 삭제하고 값을 반환 */
element delete_rear(DequeType *dq) {
    if (is_empty(dq)) {
        error("덱 공백 에러");
    } else {
        DlistNode *removed = dq->tail;
        element item = removed->data;
        dq->tail = removed->llink;
        if (dq->tail == NULL)
            dq->head = NULL;
        else
            dq->tail->rlink = NULL;
        free(removed);
        return item;
    }
}

void display(DequeType *dq) {
    for (DlistNode *p = dq->head; p != NULL; p = p->rlink)
        printf("%d ", p->data);
    printf("\n");
}

int main(void) {
    DequeType dq;
    init_deque(&dq);

    add_rear(&dq, 2);
    add_rear(&dq, 3);
    add_front(&dq, 1);
    display(&dq);                             /* 1 2 3 */

    printf("delete_front: %d\n", delete_front(&dq));  /* 1 */
    printf("delete_rear: %d\n", delete_rear(&dq));    /* 3 */
    display(&dq);                             /* 2 */

    return 0;
}
