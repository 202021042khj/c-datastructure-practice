#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 연결 리스트의 노드 */
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *create_node(element data) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

/* p 노드 뒤에 new_node 삽입. p가 NULL이면 맨 앞에 삽입 */
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
    if (*phead == NULL) {
        new_node->link = NULL;
        *phead = new_node;
    } else if (p == NULL) {
        new_node->link = *phead;
        *phead = new_node;
    } else {
        new_node->link = p->link;
        p->link = new_node;
    }
}

/* p 노드 뒤의 removed 노드 삭제. p가 NULL이면 맨 앞 노드 삭제 */
void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
    if (p == NULL)
        *phead = removed->link;
    else
        p->link = removed->link;
    free(removed);
}

void display(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("%d ", p->data);
    printf("\n");
}

int main(void) {
    ListNode *head = NULL;
    ListNode *n1, *n2, *n3;

    n1 = create_node(10);
    insert_node(&head, NULL, n1);     /* 10 */

    n2 = create_node(20);
    insert_node(&head, n1, n2);       /* 10 20 */

    n3 = create_node(5);
    insert_node(&head, NULL, n3);     /* 5 10 20 */
    display(head);                    /* 5 10 20 */

    remove_node(&head, n1, n2);       /* 20 삭제 (n1 뒤의 노드) */
    display(head);                    /* 5 10 */

    return 0;
}
