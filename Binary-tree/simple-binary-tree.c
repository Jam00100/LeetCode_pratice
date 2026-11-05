#include <stdio.h>
#include <stdlib.h>

// 定義 Binary Tree 的節點
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 建立一個新節點
struct TreeNode* createNode(int value) {
    // Step 1：配置記憶體
    struct TreeNode* node = malloc(sizeof(struct TreeNode));

    if (node == NULL) {
        return NULL;
    }

    // Step 2：設定節點數值
    node->val = value;

    // Step 3：初始化左右子節點
    node->left = NULL;
    node->right = NULL;

    // Step 4：回傳新節點的指標
    return node;
}

// 釋放整棵樹的記憶體
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    // 建立 Root
    struct TreeNode* root = createNode(1);

    // 建立左右子節點
    root->left = createNode(2);
    root->right = createNode(3);

    // 建立節點 2 的左右子節點
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // 印出節點
    printf("Root: %d\n", root->val);
    printf("Root Left: %d\n", root->left->val);
    printf("Root Right: %d\n", root->right->val);
    printf("Root Left Left: %d\n", root->left->left->val);
    printf("Root Left Right: %d\n", root->left->right->val);

    freeTree(root);

    return 0;
}