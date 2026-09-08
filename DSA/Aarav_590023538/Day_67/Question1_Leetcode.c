pp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Found the node to delete
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        // Two children: find in-order successor (smallest in right subtree)
        TreeNode* succParent = root;
        TreeNode* succ = root->right;
        while (succ->left) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root) {
            succParent->left = succ->right;
            succ->right = root->right;
        }
        succ->left = root->left;
        return succ;
    }
    return root;
}

int main() {
    // root = [5,3,6,2,4,null,7], key = 3
    // deleting 3 (two children: 2 and 4) replaces it with its in-order
    // successor 4, giving [5,4,6,2,null,null,7]

    // root = [5,3,6,2,4,null,7], key = 0
    // 0 is not present, tree is returned unchanged

    // root = [], key = 0
    // empty tree stays empty
    return 0;
}
