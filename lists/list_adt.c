#include <stdio.h>
#include <stdlib.h>

/* 연결 리스트로 구현한 리스트 ADT: 위치(pos) 기반 연산 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

void list_init(List *l) {
    l->head = NULL;
    l->size = 0;
}

int list_length(List *l) {
    return l->size;
}

/* pos는 0 ~ size 사이, 성공하면 1 반환 */
int list_insert(List *l, int pos, int value) {
    if (pos < 0 || pos > l->size)
        return 0;

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;

    if (pos == 0) {
        new_node->next = l->head;
        l->head = new_node;
    } else {
        Node *prev = l->head;
        for (int i = 0; i < pos - 1; i++)
            prev = prev->next;
        new_node->next = prev->next;
        prev->next = new_node;
    }
    l->size++;
    return 1;
}

/* pos는 0 ~ size-1, 삭제한 값을 *out에 저장 */
int list_delete(List *l, int pos, int *out) {
    if (pos < 0 || pos >= l->size)
        return 0;

    Node *target;
    if (pos == 0) {
        target = l->head;
        l->head = target->next;
    } else {
        Node *prev = l->head;
        for (int i = 0; i < pos - 1; i++)
            prev = prev->next;
        target = prev->next;
        prev->next = target->next;
    }
    *out = target->data;
    free(target);
    l->size--;
    return 1;
}

int list_get(List *l, int pos, int *out) {
    if (pos < 0 || pos >= l->size)
        return 0;

    Node *cur = l->head;
    for (int i = 0; i < pos; i++)
        cur = cur->next;
    *out = cur->data;
    return 1;
}

void list_print(List *l) {
    Node *cur = l->head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void list_clear(List *l) {
    Node *cur = l->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    l->head = NULL;
    l->size = 0;
}

int main(void) {
    List l;
    int value;

    list_init(&l);
    list_insert(&l, 0, 10);
    list_insert(&l, 1, 30);
    list_insert(&l, 1, 20);
    list_print(&l);                 /* 10 20 30 */

    list_get(&l, 2, &value);
    printf("get(2) = %d\n", value); /* 30 */

    list_delete(&l, 0, &value);
    printf("deleted = %d\n", value);/* 10 */
    list_print(&l);                 /* 20 30 */

    list_clear(&l);
    return 0;
}
