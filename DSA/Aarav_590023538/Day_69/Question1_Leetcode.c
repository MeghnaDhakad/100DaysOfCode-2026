#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int* preorder, int* idx, int n, int lower, int upper) {
    if (*idx == n || preorder[*idx] < lower || preorder[*idx] > upper)
        return NULL;
    int val = preorder[*idx];
    (*idx)++;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = build(preorder, idx, n, lower, val);
    node->right = build(preorder, idx, n, val, upper);
    return node;
}

struct TreeNode* bstFromPreorder(int* preorder, int n) {
    int idx = 0;
    return build(preorder, &idx, n, INT_MIN, INT_MAX);
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
