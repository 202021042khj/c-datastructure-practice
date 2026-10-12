#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* 맨 앞에 삽입 */
Node *insert_front(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = head;
    return new_node;
}

/* 오름차순 정렬 상태를 유지하며 삽입 */
Node *insert_sorted(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *prev = NULL;
    Node *cur = head;

    new_node->data = value;

    while (cur != NULL && cur->data < value) {
        prev = cur;
        cur = cur->next;
    }
    new_node->next = cur;

    if (prev == NULL)
        return new_node;

    prev->next = new_node;
    return head;
}

/* 값이 value인 첫 노드 삭제, 새 head 반환 */
Node *delete_node(Node *head, int value) {
    Node *prev = NULL;
    Node *cur = head;

    while (cur != NULL && cur->data != value) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return head;

    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;

    free(cur);
    return head;
}

Node *search(Node *head, int value) {
    Node *cur = head;
    while (cur != NULL) {
        if (cur->data == value)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void print_list(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {
    Node *head = NULL;

    head = insert_sorted(head, 30);
    head = insert_sorted(head, 10);
    head = insert_sorted(head, 20);
    print_list(head);              /* 10 20 30 */

    head = delete_node(head, 20);
    print_list(head);              /* 10 30 */

    free_list(head);
    return 0;
}
