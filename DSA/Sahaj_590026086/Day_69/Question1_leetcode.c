#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int* preorder, int n, int* idx, int bound) {
    if (*idx >= n || preorder[*idx] > bound) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[(*idx)++];
    root->left = build(preorder, n, idx, root->val);
    root->right = build(preorder, n, idx, bound);
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int idx = 0;
    return build(preorder, preorderSize, &idx, 1e9);
}

int main() {
    int p[] = {8, 5, 1, 7, 10, 12};
    struct TreeNode* r = bstFromPreorder(p, 6);
    printf("%d\n", r->val);
    return 0;
}
