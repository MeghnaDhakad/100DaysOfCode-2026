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

bool evaluateTree(TreeNode* root) {
    if (!root->left && !root->right) return root->val == 1; // leaf: 0=False, 1=True

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    return (root->val == 2) ? (left || right) : (left && right); // 2=OR, 3=AND
}

int main() {
    vector<int> v1 = {2, 1, 3, NIL, NIL, 0, 1};
    TreeNode* r1 = buildTree(v1);
    cout << boolalpha << evaluateTree(r1) << endl; // true

    vector<int> v2 = {0};
    TreeNode* r2 = buildTree(v2);
    cout << boolalpha << evaluateTree(r2) << endl; // false

    return 0;
}
