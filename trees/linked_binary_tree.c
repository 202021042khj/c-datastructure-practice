#include <stdio.h>
#include <stdlib.h>

typedef int element;

/* 링크로 구현한 이진 트리의 노드 */
typedef struct TreeNode {
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void inorder(TreeNode *root) {
    if (root == NULL) {
        return;
    } else {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(void) {
    TreeNode *n1, *n2, *n3, *n4, *n5;

    /*        1
     *      /   \
     *     2     3
     *    / \
     *   4   5
     */
    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n1->data = 1;
    n1->left = NULL;
    n1->right = NULL;

    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n2->data = 2;
    n2->left = NULL;
    n2->right = NULL;

    n3 = (TreeNode *)malloc(sizeof(TreeNode));
    n3->data = 3;
    n3->left = NULL;
    n3->right = NULL;

    n4 = (TreeNode *)malloc(sizeof(TreeNode));
    n4->data = 4;
    n4->left = NULL;
    n4->right = NULL;

    n5 = (TreeNode *)malloc(sizeof(TreeNode));
    n5->data = 5;
    n5->left = NULL;
    n5->right = NULL;

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    inorder(n1);                    /* 4 2 5 1 3 */
    printf("\n");

    free(n5);
    free(n4);
    free(n3);
    free(n2);
    free(n1);
    return 0;
}
