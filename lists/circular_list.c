#include <stdio.h>
#include <stdlib.h>

/* 원형 연결 리스트: 마지막 노드의 next가 head를 가리킴 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insert_front(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;

    if (head == NULL) {
        new_node->next = new_node;
        return new_node;
    }

    Node *last = head;
    while (last->next != head)
        last = last->next;

    new_node->next = head;
    last->next = new_node;
    return new_node;   /* 새 노드가 head */
}

Node *delete_value(Node *head, int value) {
    if (head == NULL)
        return NULL;

    Node *prev = head;
    Node *cur = head;

    while (cur->data != value) {
        prev = cur;
        cur = cur->next;
        if (cur == head)       /* 한 바퀴 돌았는데 없음 */
            return head;
    }

    if (cur->next == cur) {    /* 노드가 하나뿐 */
        free(cur);
        return NULL;
    }

    if (cur == head) {         /* head 삭제: 마지막 노드를 찾아 연결 갱신 */
        Node *last = head;
        while (last->next != head)
            last = last->next;
        Node *new_head = head->next;
        last->next = new_head;
        free(head);
        return new_head;
    }

    prev->next = cur->next;
    free(cur);
    return head;
}

void print_list(Node *head) {
    if (head == NULL) {
        printf("(empty)\n");
        return;
    }
    Node *cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

int main(void) {
    Node *head = NULL;

    head = insert_front(head, 3);
    head = insert_front(head, 2);
    head = insert_front(head, 1);
    print_list(head);              /* 1 2 3 */

    head = delete_value(head, 1);
    print_list(head);              /* 2 3 */

    return 0;
}
