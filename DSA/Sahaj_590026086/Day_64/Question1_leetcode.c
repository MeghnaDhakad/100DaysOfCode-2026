#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (!root) return 0;
    if (root->val < low) return rangeSumBST(root->right, low, high);
    if (root->val > high) return rangeSumBST(root->left, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    struct TreeNode r = {10, NULL, NULL};
    struct TreeNode l = {5, NULL, NULL};
    struct TreeNode ri = {15, NULL, NULL};
    r.left = &l; r.right = &ri;
    printf("%d\n", rangeSumBST(&r, 7, 15));
    return 0;
}
