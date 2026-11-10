#include <stdio.h>
#include <stdlib.h>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    // 檢查root
    if (root == NULL){
        return 0;
    }

    // Step 1：暫存右子樹指標
    struct TreeNode* temp = root->right;

    // Step 2：交換左右子樹指標
    root->right = root->left;
    root->left = temp;

    root -> right, root -> left = root -> left, temp;

    invertTree(root -> right);
    invertTree(root -> left);
    
    return root;
}