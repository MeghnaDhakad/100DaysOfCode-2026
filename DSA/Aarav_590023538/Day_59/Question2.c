#include <stdio.h>
#include <stdlib.h>

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

/* Builds the tree directly from heap-array indexing: node i's children live
   at 2i+1 and 2i+2; -1 (or an out-of-range index) means missing. */
TreeNode* build(int *tree, int n, int idx) {
    if (idx >= n || tree[idx] == -1) return NULL;

    TreeNode* node = newNode(tree[idx]);
    node->left = build(tree, n, 2 * idx + 1);
    node->right = build(tree, n, 2 * idx + 2);
    return node;
}

int countPopcount(unsigned mask) {
    int c = 0;
    while (mask) { c += mask & 1; mask >>= 1; }
    return c;
}

/* mask has one bit per digit (0-9); a set bit means that digit's count
   is currently odd along the path so far. */
int countValidPaths(TreeNode* root, unsigned mask) {
    if (!root) return 0;

    mask ^= (1u << root->val);

    if (!root->left && !root->right) {
        return countPopcount(mask) <= 1 ? 1 : 0; // leaf: check palindrome-rearrangeable
    }

    return countValidPaths(root->left, mask) + countValidPaths(root->right, mask);
}

int main(void) {
    int t1[] = {2, 3, 1, 3, 1, -1, 1};
    TreeNode* r1 = build(t1, 7, 0);
    printf("%d\n", countValidPaths(r1, 0)); // 2

    int t2[] = {1, 1, 1};
    TreeNode* r2 = build(t2, 3, 0);
    printf("%d\n", countValidPaths(r2, 0)); // 2

    int t3[] = {5};
    TreeNode* r3 = build(t3, 1, 0);
    printf("%d\n", countValidPaths(r3, 0)); // 1

    return 0;
}
