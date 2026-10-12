#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

/* 원소 타입이 구조체인 스택 */
typedef struct {
    int id;
    char name[20];
} element;

/* 전역 배열과 top으로 구현한 스택: top은 마지막 원소의 인덱스, 비었을 때 -1 */
element stack[MAX_STACK_SIZE];
int top = -1;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
    if (is_full()) {
        error("스택 포화 에러");
    } else {
        stack[++top] = item;
    }
}

element pop() {
    if (is_empty()) {
        error("스택 공백 에러");
    } else {
        return stack[top--];
    }
}

element peek() {
    if (is_empty()) {
        error("스택 공백 에러");
    } else {
        return stack[top];
    }
}

int main(void) {
    element a = {1, "apple"};
    element b = {2, "banana"};
    element item;

    push(a);
    push(b);

    item = peek();
    printf("peek: %d %s\n", item.id, item.name);   /* 2 banana */

    item = pop();
    printf("pop: %d %s\n", item.id, item.name);    /* 2 banana */
    item = pop();
    printf("pop: %d %s\n", item.id, item.name);    /* 1 apple */

    return 0;
}
