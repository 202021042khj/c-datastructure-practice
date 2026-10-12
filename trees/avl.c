#include <stdio.h>
#include <stdlib.h>

/* 균형 이진 탐색 트리(AVL): 삽입 후 높이 차이가 2 이상이면 회전으로 균형 유지 */
typedef struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

static int max2(int a, int b) {
    return a > b ? a : b;
}

static int height(Node *node) {
    return node == NULL ? 0 : node->height;
}

static void update_height(Node *node) {
    node->height = 1 + max2(height(node->left), height(node->right));
}

/* 왼쪽 자식 - 부모 높이 차이 */
static int balance_factor(Node *node) {
    return node == NULL ? 0 : height(node->left) - height(node->right);
}

/* LL 회전 */
static Node *rotate_right(Node *y) {
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    update_height(y);
    update_height(x);
    return x;
}

/* RR 회전 */
static Node *rotate_left(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    update_height(x);
    update_height(y);
    return y;
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->key = key;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;            /* 중복 무시 */

    update_height(node);
    int bf = balance_factor(node);

    /* LL */
    if (bf > 1 && key < node->left->key)
        return rotate_right(node);
    /* RR */
    if (bf < -1 && key > node->right->key)
        return rotate_left(node);
    /* LR */
    if (bf > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    /* RL */
    if (bf < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void free_tree(Node *root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25};

    /* 10, 20, 30을 넣으면 RR 회전이 일어나 루트가 20이 됨 */
    for (int i = 0; i < 6; i++)
        root = insert(root, keys[i]);

    printf("root: %d, height: %d\n", root->key, root->height);
    inorder(root);                  /* 10 20 25 30 40 50 */
    printf("\n");

    free_tree(root);
    return 0;
}
