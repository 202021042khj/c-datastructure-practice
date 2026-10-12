#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;

/* 배열로 구현한 스택: top은 마지막 원소의 인덱스, 비었을 때 -1 */
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
    if (is_full(s))
        error("스택 포화 에러");
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s))
        error("스택 공백 에러");
    return s->data[(s->top)--];
}

element peek(StackType *s) {
    if (is_empty(s))
        error("스택 공백 에러");
    return s->data[s->top];
}

int main(void) {
    StackType s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("peek: %d\n", peek(&s));   /* 3 */
    printf("pop: %d\n", pop(&s));     /* 3 */
    printf("pop: %d\n", pop(&s));     /* 2 */

    return 0;
}
