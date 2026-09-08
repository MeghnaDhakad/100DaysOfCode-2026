#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode* root, int* arr, int* idx) {
    if (!root) return;
    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->val;
    inorder(root->right, arr, idx);
}

struct TreeNode* buildBalanced(int* arr, int left, int right) {
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = arr[mid];
    node->left = buildBalanced(arr, left, mid - 1);
    node->right = buildBalanced(arr, mid + 1, right);
    return node;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int arr[10001];
    int idx = 0;
    inorder(root, arr, &idx);
    return buildBalanced(arr, 0, idx - 1);
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
