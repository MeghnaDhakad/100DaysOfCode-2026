#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode* root, int* prev, int* count, int* maxCount, int* modes, int* modeCount, int pass) {
    if (!root) return;
    inorder(root->left, prev, count, maxCount, modes, modeCount, pass);
    if (*prev == root->val) (*count)++; else { *count = 1; *prev = root->val; }
    if (pass == 1) { if (*count > *maxCount) *maxCount = *count; }
    else { if (*count == *maxCount) modes[(*modeCount)++] = root->val; }
    inorder(root->right, prev, count, maxCount, modes, modeCount, pass);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int prev = -1e9, count = 0, maxCount = 0, modeCount = 0;
    inorder(root, &prev, &count, &maxCount, NULL, &modeCount, 1);
    int* modes = (int*)malloc(1000 * sizeof(int));
    prev = -1e9; count = 0; modeCount = 0;
    inorder(root, &prev, &count, &maxCount, modes, &modeCount, 2);
    *returnSize = modeCount;
    return modes;
}

int main() {
    struct TreeNode r = {1, NULL, NULL};
    struct TreeNode ri = {2, NULL, NULL};
    r.right = &ri;
    int sz;
    int* res = findMode(&r, &sz);
    for (int i = 0; i < sz; i++) printf("%d ", res[i]);
    printf("\n");
    free(res);
    return 0;
}
