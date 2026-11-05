#include <stdio.h>
#include <stdlib.h>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    
    // 檢查root
    if (root == NULL){
        return 0;
    }

    // 尋找left/right tree的最深處
    int left_max = maxDepth(root -> left);
    int right_max = maxDepth(root -> right);

    // 比較兩邊深度LeetCode用node計算depth，所以這邊要+1
    if (left_max > right_max){
        return left_max + 1;
    }
    else {
        return right_max + 1;
    }
}