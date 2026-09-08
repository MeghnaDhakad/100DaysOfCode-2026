#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NIL INT_MIN /* sentinel marking a missing node in the input array */
#define MAXN 10000

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

/* Standard LeetCode-style level-order build: NIL entries are skipped. */
TreeNode* buildTree(int *vals, int n) {
    if (n == 0 || vals[0] == NIL) return NULL;

    TreeNode* root = newNode(vals[0]);
    TreeNode* q[MAXN];
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

/* Globals used during the single inorder pass */
int g_hasPrev = 0;
int g_prevVal = 0;
int g_curCount = 0;
int g_maxCount = 0;
int g_modes[MAXN];
int g_modeCount = 0;

void inorder(TreeNode* node) {
    if (!node) return;

    inorder(node->left);

    if (g_hasPrev && node->val == g_prevVal) g_curCount++;
    else g_curCount = 1;

    if (g_curCount > g_maxCount) {
        g_maxCount = g_curCount;
        g_modeCount = 0;
        g_modes[g_modeCount++] = node->val;
    } else if (g_curCount == g_maxCount) {
        g_modes[g_modeCount++] = node->val;
    }

    g_prevVal = node->val;
    g_hasPrev = 1;

    inorder(node->right);
}

void resetState(void) {
    g_hasPrev = 0;
    g_curCount = 0;
    g_maxCount = 0;
    g_modeCount = 0;
}

void printModes(void) {
    printf("[");
    for (int i = 0; i < g_modeCount; i++) {
        printf("%d%s", g_modes[i], (i == g_modeCount - 1) ? "" : ",");
    }
    printf("]\n");
}

int main(void) {
    int v1[] = {1, NIL, 2, 2};
    TreeNode* r1 = buildTree(v1, 4);
    resetState();
    inorder(r1);
    printModes(); // [2]

    int v2[] = {0};
    TreeNode* r2 = buildTree(v2, 1);
    resetState();
    inorder(r2);
    printModes(); // [0]

    return 0;
}
