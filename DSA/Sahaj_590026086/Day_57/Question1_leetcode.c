#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int helper(struct TreeNode* root, int isLeft) {
    if (!root) return 0;
    if (!root->left && !root->right) return isLeft ? root->val : 0;
    return helper(root->left, 1) + helper(root->right, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return helper(root, 0);
}

int main() {
    struct TreeNode root = {3, NULL, NULL};
    struct TreeNode l = {9, NULL, NULL};
    struct TreeNode r = {20, NULL, NULL};
    root.left = &l; root.right = &r;
    printf("%d\n", sumOfLeftLeaves(&root));
    return 0;
}
