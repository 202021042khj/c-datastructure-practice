#include <stdio.h>
#include <stdlib.h>

/* 이중 연결 리스트: prev와 next 두 방향으로 연결 */
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *insert_front(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;
    return new_node;
}

Node *insert_back(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        return new_node;
    }

    Node *last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
    return head;
}

Node *delete_value(Node *head, int value) {
    Node *cur = head;
    while (cur != NULL && cur->data != value)
        cur = cur->next;

    if (cur == NULL)
        return head;

    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        head = cur->next;          /* head 삭제 */

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    free(cur);
    return head;
}

void print_forward(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void print_backward(Node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    Node *cur = tail;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

int main(void) {
    Node *head = NULL;

    head = insert_back(head, 2);
    head = insert_back(head, 3);
    head = insert_front(head, 1);
    print_forward(head);           /* 1 2 3 */
    print_backward(head);          /* 3 2 1 */

    head = delete_value(head, 2);
    print_forward(head);           /* 1 3 */

    return 0;
}
