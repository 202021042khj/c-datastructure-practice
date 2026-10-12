#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 이중 연결 리스트의 노드: llink(왼쪽), rlink(오른쪽) */
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

/* 더미 헤드 노드를 사용: 리스트가 비어 있어도 head 노드 하나는 항상 있음 */

DlistNode *create_node(element data) {
    DlistNode *node = (DlistNode *)malloc(sizeof(DlistNode));
    node->data = data;
    node->llink = NULL;
    node->rlink = NULL;
    return node;
}

void init_dlist(DlistNode *head) {
    head->llink = head;
    head->rlink = head;
}

/* before 노드의 오른쪽에 new_node 삽입 */
void dinsert_node(DlistNode *before, DlistNode *new_node) {
    new_node->llink = before;
    new_node->rlink = before->rlink;
    before->rlink->llink = new_node;
    before->rlink = new_node;
}

/* removed 노드 삭제 (더미 헤드는 삭제하지 않음) */
void ddelete_node(DlistNode *head, DlistNode *removed) {
    if (removed == head)
        return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void display(DlistNode *head) {
    for (DlistNode *p = head->rlink; p != head; p = p->rlink)
        printf("%d ", p->data);
    printf("\n");
}

void display_reverse(DlistNode *head) {
    for (DlistNode *p = head->llink; p != head; p = p->llink)
        printf("%d ", p->data);
    printf("\n");
}

int main(void) {
    DlistNode *head = create_node(0);     /* 더미 헤드 */
    DlistNode *n10, *n20;

    init_dlist(head);

    n10 = create_node(10);
    dinsert_node(head, n10);              /* 10 */

    n20 = create_node(20);
    dinsert_node(n10, n20);               /* 10 20 */

    dinsert_node(head, create_node(5));   /* 5 10 20 */
    display(head);                        /* 5 10 20 */
    display_reverse(head);                /* 20 10 5 */

    ddelete_node(head, n10);              /* 10 삭제 */
    display(head);                        /* 5 20 */

    return 0;
}
