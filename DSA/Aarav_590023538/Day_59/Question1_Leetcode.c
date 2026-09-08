#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NIL INT_MIN /* sentinel marking a missing node in the input array */

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

/* Standard LeetCode-style level-order build: NIL entries are simply
   skipped (no node created), matching how root = [1,2,3,4,5,null,7] is read. */
TreeNode* buildTree(int *vals, int n) {
    if (n == 0 || vals[0] == NIL) return NULL;

    TreeNode* root = newNode(vals[0]);
    TreeNode* q[1000];
    int qh = 0, qt = 0;
    q[qt++] = root;

    int i = 1;
    while (qh < qt && i < n) {
        TreeNode* node = q[qh++];
        if (i < n) {
            if (vals[i] != NIL) { node->left = newNode(vals[i]); q[qt++] = node->left; }
            i++;
        }
        if (i < n) {
            if (vals[i] != NIL) { node->right = newNode(vals[i]); q[qt++] = node->right; }
            i++;
        }
    }
    return root;
}

int isCompleteTree(TreeNode* root) {
    if (!root) return 1;

    TreeNode* q[1000];
    int qh = 0, qt = 0;
    q[qt++] = root;
    int seenNull = 0;

    while (qh < qt) {
        TreeNode* node = q[qh++];

        if (!node) {
            seenNull = 1;
            continue;
        }
        if (seenNull) return 0; // a real node showed up after a gap -> not complete

        q[qt++] = node->left;
        q[qt++] = node->right;
    }
    return 1;
}

int main(void) {
    int v1[] = {1, 2, 3, 4, 5, 6};
    TreeNode* r1 = buildTree(v1, 6);
    printf("%s\n", isCompleteTree(r1) ? "true" : "false"); // true

    int v2[] = {1, 2, 3, 4, 5, NIL, 7};
    TreeNode* r2 = buildTree(v2, 7);
    printf("%s\n", isCompleteTree(r2) ? "true" : "false"); // false

    return 0;
}
