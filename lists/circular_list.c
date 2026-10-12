#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 원형 연결 리스트의 노드 */
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

/* head는 마지막 노드를 가리키고, 첫 노드는 head->link */

ListNode *create_node(element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->link = NULL;
    return node;
}

void insert_first(ListNode **phead, ListNode *node) {
    if (*phead == NULL) {
        node->link = node;
        *phead = node;
    } else {
        node->link = (*phead)->link;
        (*phead)->link = node;
    }
}

/* 마지막에 삽입: 첫 노드 앞에 넣은 뒤 head를 새 노드로 옮김 */
void insert_last(ListNode **phead, ListNode *node) {
    insert_first(phead, node);
    *phead = node;
}

/* 첫 노드 삭제 */
void delete_first(ListNode **phead) {
    if (*phead == NULL)
        return;

    ListNode *removed = (*phead)->link;
    if (removed == *phead) {          /* 노드가 하나뿐 */
        *phead = NULL;
    } else {
        (*phead)->link = removed->link;
    }
    free(removed);
}

void display(ListNode *head) {
    if (head == NULL) {
        printf("(empty)\n");
        return;
    }
    ListNode *p = head->link;
    do {
        printf("%d ", p->data);
        p = p->link;
    } while (p != head->link);
    printf("\n");
}

int main(void) {
    ListNode *head = NULL;

    insert_last(&head, create_node(10));   /* 10 */
    insert_last(&head, create_node(20));   /* 10 20 */
    insert_first(&head, create_node(5));   /* 5 10 20 */
    display(head);                         /* 5 10 20 */

    delete_first(&head);                   /* 5 삭제 */
    display(head);                         /* 10 20 */

    return 0;
}
