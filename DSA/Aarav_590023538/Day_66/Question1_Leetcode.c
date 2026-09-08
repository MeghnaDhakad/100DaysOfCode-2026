pp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

const int NIL = INT_MIN;

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    vector<int> v1 = {4,2,7,1,3};
    TreeNode* r1 = buildTree(v1);
    r1 = insertIntoBST(r1, 5);
    // r1 now serializes to [4,2,7,1,3,5]

    vector<int> v2 = {40,20,60,10,30,50,70};
    TreeNode* r2 = buildTree(v2);
    r2 = insertIntoBST(r2, 25);
    // r2 now serializes to [40,20,60,10,30,50,70,null,null,25]

    return 0;
}
