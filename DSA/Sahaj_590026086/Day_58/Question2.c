#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->val == n1 || root->val == n2) return root;
    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    struct Node root = {1, NULL, NULL};
    struct Node l = {2, NULL, NULL};
    struct Node r = {3, NULL, NULL};
    root.left = &l; root.right = &r;
    struct Node* lca = findLCA(&root, 2, 3);
    if (lca) printf("%d\n", lca->val);
    return 0;
}
