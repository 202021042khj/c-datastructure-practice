#include <stdio.h>

#define MAX_SIZE 10

/* 전역 배열과 top으로 구현한 정수 스택 */
static int stack[MAX_SIZE];
static int top = -1;

int is_empty(void) {
    return top == -1;
}

int is_full(void) {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (is_full()) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop(void) {
    if (is_empty()) {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek(void) {
    if (is_empty())
        return -1;
    return stack[top];
}

int main(void) {
    push(1);
    push(2);
    push(3);
    printf("peek: %d\n", peek());  /* 3 */
    printf("pop: %d\n", pop());    /* 3 */
    printf("pop: %d\n", pop());    /* 2 */
    return 0;
}
