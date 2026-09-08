#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) { return a > b ? a : b; }

int depth(struct TreeNode* root, int* max_d) {
    if (!root) return 0;
    int l = depth(root->left, max_d);
    int r = depth(root->right, max_d);
    if (l + r > *max_d) *max_d = l + r;
    return 1 + max(l, r);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int max_d = 0;
    depth(root, &max_d);
    return max_d;
}

int main() {
    struct TreeNode r = {1, NULL, NULL};
    printf("%d\n", diameterOfBinaryTree(&r));
    return 0;
}
