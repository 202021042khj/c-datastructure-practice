#include <stdio.h>
#include <stdlib.h>

/* 링크로 구현한 이진 트리 */
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

void inorder_print(Node *root) {
    if (root == NULL)
        return;
    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

void free_tree(Node *root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int count_nodes(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int tree_height(Node *root) {
    if (root == NULL)
        return 0;
    int l = tree_height(root->left);
    int r = tree_height(root->right);
    return 1 + (l > r ? l : r);
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

    inorder_print(root);                       /* 4 2 5 1 3 */
    printf("\nnodes: %d\n", count_nodes(root)); /* 5 */
    printf("height: %d\n", tree_height(root));  /* 3 */

    free_tree(root);
    return 0;
}
