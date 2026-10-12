#include <stdio.h>
#include <stdlib.h>

/* 이진 트리 순회: 전위, 중위, 후위, 레벨 순서 */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *make_node(int data, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

void preorder(Node *root) {          /* 루트 - 왼쪽 - 오른쪽 */
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {           /* 왼쪽 - 루트 - 오른쪽 */
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root) {         /* 왼쪽 - 오른쪽 - 루트 */
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* 레벨 순서: 배열 큐 사용 */
void levelorder(Node *root) {
    Node *queue[100];
    int front = 0, rear = 0;

    if (root == NULL)
        return;

    queue[rear++] = root;
    while (front < rear) {
        Node *cur = queue[front++];
        printf("%d ", cur->data);
        if (cur->left != NULL)
            queue[rear++] = cur->left;
        if (cur->right != NULL)
            queue[rear++] = cur->right;
    }
}

void free_tree(Node *root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    /*        1
     *      /   \
     *     2     3
     *    / \
     *   4   5
     */
    Node *root = make_node(1,
                    make_node(2, make_node(4, NULL, NULL), make_node(5, NULL, NULL)),
                    make_node(3, NULL, NULL));

    printf("preorder:  "); preorder(root);   printf("\n"); /* 1 2 4 5 3 */
    printf("inorder:   "); inorder(root);    printf("\n"); /* 4 2 5 1 3 */
    printf("postorder: "); postorder(root);  printf("\n"); /* 4 5 2 3 1 */
    printf("levelorder:"); levelorder(root); printf("\n"); /* 1 2 3 4 5 */

    free_tree(root);
    return 0;
}
