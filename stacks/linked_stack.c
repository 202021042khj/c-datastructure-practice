#include <stdio.h>
#include <stdlib.h>

/* 연결 리스트로 구현한 스택: 맨 앞이 top */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int is_empty(Node *top) {
    return top == NULL;
}

Node *push(Node *top, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = top;
    return new_node;
}

/* 성공하면 1 반환, 꺼낸 값은 *out에 저장, 새 top은 *top_ref에 저장 */
int pop(Node **top_ref, int *out) {
    if (is_empty(*top_ref)) {
        printf("Underflow\n");
        return 0;
    }
    Node *old = *top_ref;
    *out = old->data;
    *top_ref = old->next;
    free(old);
    return 1;
}

int peek(Node *top) {
    if (is_empty(top))
        return -1;
    return top->data;
}

int main(void) {
    Node *top = NULL;
    int value;

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    printf("peek: %d\n", peek(top));  /* 3 */

    pop(&top, &value);
    printf("pop: %d\n", value);       /* 3 */
    pop(&top, &value);
    printf("pop: %d\n", value);       /* 2 */
    return 0;
}
