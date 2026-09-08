#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(int v) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

/* 1-indexed heap-style build: node at position i (1-indexed) has children
   at positions 2i and 2i+1. tree[] is stored 0-indexed, so position i maps
   to array index i-1. -1 or an out-of-range position means missing. */
TreeNode* build(int *tree, int n, int pos) {
    if (pos > n || tree[pos - 1] == -1) return NULL;

    TreeNode* node = newNode(tree[pos - 1]);
    node->left = build(tree, n, 2 * pos);
    node->right = build(tree, n, 2 * pos + 1);
    return node;
}

int closestValue(TreeNode* root, double target) {
    int best = root->val;
    double bestDiff = fabs(root->val - target);

    TreeNode* cur = root;
    while (cur) {
        double diff = fabs(cur->val - target);
        if (diff < bestDiff || (diff == bestDiff && cur->val < best)) {
            best = cur->val;
            bestDiff = diff;
        }

        if (target < cur->val) cur = cur->left;
        else if (target > cur->val) cur = cur->right;
        else break;
    }
    return best;
}

int main(void) {
    int t1[] = {4, 2, 5, 1, 3, -1, -1};
    TreeNode* r1 = build(t1, 7, 1);
    printf("%d\n", closestValue(r1, 3.0)); // 3

    int t2[] = {4, 2, 5, 1, 3, -1, -1};
    TreeNode* r2 = build(t2, 7, 1);
    printf("%d\n", closestValue(r2, 3.7)); // 4

    int t3[] = {1, -1, 3};
    TreeNode* r3 = build(t3, 3, 1);
    printf("%d\n", closestValue(r3, 2.0)); // 1

    return 0;
}
