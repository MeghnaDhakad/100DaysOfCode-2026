pp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

const int NIL = INT_MIN; // sentinel for a missing node in the input vector

TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == NIL) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();

        if (i < vals.size()) {
            if (vals[i] != NIL) { node->left = new TreeNode(vals[i]); q.push(node->left); }
            i++;
        }
        if (i < vals.size()) {
            if (vals[i] != NIL) { node->right = new TreeNode(vals[i]); q.push(node->right); }
            i++;
        }
    }
    return root;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    if (root->val < low) return rangeSumBST(root->right, low, high);  // whole left subtree too small
    if (root->val > high) return rangeSumBST(root->left, low, high);  // whole right subtree too big

    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    vector<int> v1 = {10, 5, 15, 3, 7, NIL, 18};
    TreeNode* r1 = buildTree(v1);
    cout << rangeSumBST(r1, 7, 15) << endl; // 32

    vector<int> v2 = {10, 5, 15, 3, 7, 13, 18, 1, NIL, 6};
    TreeNode* r2 = buildTree(v2);
    cout << rangeSumBST(r2, 6, 10) << endl; // 23

    return 0;
}
