#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main() {
    struct TreeNode t1 = {1, NULL, NULL};
    struct TreeNode t2 = {2, NULL, NULL};
    struct TreeNode* res = mergeTrees(&t1, &t2);
    printf("%d\n", res->val);
    return 0;
}
