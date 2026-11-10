#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL){
        return true;
    }
    if (p == NULL || q == NULL){
        return false;
    }

    if (p -> val != q -> val){
        return false;
    }
    bool right_same = isSameTree(p -> left, q -> left);
    bool left_same = isSameTree(p -> right, q -> right);

    return right_same && left_same;
}