#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Step 1：計算 Tree 的節點總數
int countNodes(struct TreeNode* node) {

    if (node == NULL) {
        return 0;
    }

    return 1 + countNodes(node->left)
             + countNodes(node->right);
}

// Step 2：Inorder Traversal
void inorder(struct TreeNode* node, int* result, int* index) {

    if (node == NULL) {
        return;
    }

    // Left
    inorder(node->left, result, index);

    // Root
    result[*index] = node->val;
    (*index)++;

    // Right
    inorder(node->right, result, index);
}

// Step 3：LeetCode 主函式
int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    // 計算節點總數
    int count = countNodes(root);

    // 告訴 LeetCode 回傳陣列大小
    *returnSize = count;

    // 空樹直接回傳 NULL
    if (count == 0) {
        return NULL;
    }

    // 配置結果陣列
    int* result = malloc(sizeof(int) * count);

    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 紀錄目前寫入位置
    int index = 0;

    // 執行 Inorder Traversal
    inorder(root, result, &index);

    return result;
}