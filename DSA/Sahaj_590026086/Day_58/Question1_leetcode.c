#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getLeftHeight(struct TreeNode* node) { int h = 0; while (node) { h++; node = node->left; } return h; }
int getRightHeight(struct TreeNode* node) { int h = 0; while (node) { h++; node = node->right; } return h; }

int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);
    if (lh == rh) return (1 << lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct TreeNode r = {1, NULL, NULL};
    printf("%d\n", countNodes(&r));
    return 0;
}
