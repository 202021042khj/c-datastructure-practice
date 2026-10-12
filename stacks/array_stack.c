#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top >= MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Empty\n");
        return -1;
    }
    return s->data[s->top];
}

int main(void) {
    Stack s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("peek: %d\n", peek(&s));   /* 3 */
    printf("pop: %d\n", pop(&s));     /* 3 */
    printf("pop: %d\n", pop(&s));     /* 2 */

    return 0;
}
