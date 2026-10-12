#include <stdio.h>
#include <stdlib.h>

/* 이진 탐색 트리: 왼쪽 < 루트 < 오른쪽 */
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int key) {
    if (root == NULL) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;                /* 중복 키는 무시 */
}

Node *search(Node *root, int key) {
    while (root != NULL && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;                /* 없으면 NULL */
}

Node *min_node(Node *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node *delete_node(Node *root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        /* 자식이 0개 또는 1개 */
        if (root->left == NULL) {
            Node *right = root->right;
            free(root);
            return right;
        }
        if (root->right == NULL) {
            Node *left = root->left;
            free(root);
            return left;
        }
        /* 자식이 2개: 오른쪽 서브트리의 최솟값으로 대체 */
        Node *successor = min_node(root->right);
        root->key = successor->key;
        root->right = delete_node(root->right, successor->key);
    }
    return root;
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
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, keys[i]);

    inorder(root);                              /* 20 30 40 50 60 70 80 */
    printf("\n");
    printf("search 40: %s\n", search(root, 40) ? "found" : "not found");

    root = delete_node(root, 30);               /* 자식 2개인 노드 삭제 */
    inorder(root);                              /* 20 40 50 60 70 80 */
    printf("\n");

    free_tree(root);
    return 0;
}
