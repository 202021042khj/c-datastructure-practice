#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 연결 리스트로 구현한 스택의 노드 */
typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

/* top은 맨 앞 노드를 가리킴, 비었을 때 NULL */
typedef struct {
    StackNode *top;
} LinkedStackType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_stack(LinkedStackType *s) {
    s->top = NULL;
}

int is_empty(LinkedStackType *s) {
    return (s->top == NULL);
}

/* 맨 앞에 새 노드를 넣음 */
void push(LinkedStackType *s, element item) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if (temp == NULL) {
        error("메모리 할당 에러");
    } else {
        temp->data = item;
        temp->link = s->top;
        s->top = temp;
    }
}

element pop(LinkedStackType *s) {
    if (is_empty(s)) {
        error("스택 공백 에러");
    } else {
        StackNode *temp = s->top;
        element item = temp->data;
        s->top = temp->link;
        free(temp);
        return item;
    }
}

element peek(LinkedStackType *s) {
    if (is_empty(s)) {
        error("스택 공백 에러");
    } else {
        return s->top->data;
    }
}

int main(void) {
    LinkedStackType s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("peek: %d\n", peek(&s));   /* 3 */
    printf("pop: %d\n", pop(&s));     /* 3 */
    printf("pop: %d\n", pop(&s));     /* 2 */

    return 0;
}
