#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool evaluateTree(struct TreeNode* root) {
    if (!root->left && !root->right) return root->val == 1;
    bool l = evaluateTree(root->left);
    bool r = evaluateTree(root->right);
    if (root->val == 2) return l || r;
    return l && r;
}

int main() {
    struct TreeNode r = {2, NULL, NULL};
    struct TreeNode l = {1, NULL, NULL};
    struct TreeNode ri = {0, NULL, NULL};
    r.left = &l; r.right = &ri;
    printf("%s\n", evaluateTree(&r) ? "true" : "false");
    return 0;
}
