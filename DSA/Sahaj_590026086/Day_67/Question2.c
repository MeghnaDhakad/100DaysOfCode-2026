#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkHeight(struct TreeNode* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    if (lh == -1) return -1;
    int rh = checkHeight(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return 1 + (lh > rh ? lh : rh);
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    struct TreeNode r = {1, NULL, NULL};
    printf("%s\n", isBalanced(&r) ? "true" : "false");
    return 0;
}
