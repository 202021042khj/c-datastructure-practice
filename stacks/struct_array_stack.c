#include <stdio.h>

#define MAX_SIZE 10

/* 구조체를 원소로 갖는 배열 스택 */
typedef struct {
    int id;
    char name[20];
} Item;

typedef struct {
    Item data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, Item item) {
    if (is_full(s)) {
        printf("Overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

/* 성공하면 1, 실패하면 0 반환. 꺼낸 값은 *out에 저장 */
int pop(Stack *s, Item *out) {
    if (is_empty(s)) {
        printf("Underflow\n");
        return 0;
    }
    *out = s->data[(s->top)--];
    return 1;
}

int main(void) {
    Stack s;
    Item item;
    Item a = {1, "apple"};
    Item b = {2, "banana"};

    init_stack(&s);
    push(&s, a);
    push(&s, b);

    pop(&s, &item);
    printf("%d %s\n", item.id, item.name);   /* 2 banana */
    pop(&s, &item);
    printf("%d %s\n", item.id, item.name);   /* 1 apple */
    return 0;
}
