#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* getMin(struct TreeNode* node) {
    while (node->left) node = node->left;
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return NULL;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { struct TreeNode* temp = root->right; free(root); return temp; }
        if (!root->right) { struct TreeNode* temp = root->left; free(root); return temp; }
        struct TreeNode* temp = getMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main() {
    struct TreeNode r = {5, NULL, NULL};
    struct TreeNode* res = deleteNode(&r, 5);
    printf("%s\n", res == NULL ? "deleted" : "not deleted");
    return 0;
}
