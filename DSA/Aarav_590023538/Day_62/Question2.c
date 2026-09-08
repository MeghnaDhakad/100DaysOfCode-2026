pp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Builds the tree directly from heap-array indexing: node i's children live
// at 2i+1 and 2i+2; -1 (or an out-of-range index) means missing.
TreeNode* build(vector<int>& tree, int idx) {
    if (idx >= (int)tree.size() || tree[idx] == -1) return nullptr;

    TreeNode* node = new TreeNode(tree[idx]);
    node->left = build(tree, 2 * idx + 1);
    node->right = build(tree, 2 * idx + 2);
    return node;
}

// Returns {maxWithNodeRobbed, maxWithoutNodeRobbed}
pair<int,int> robHelper(TreeNode* node) {
    if (!node) return {0, 0};

    auto [leftWith, leftWithout] = robHelper(node->left);
    auto [rightWith, rightWithout] = robHelper(node->right);

    int withNode = node->val + leftWithout + rightWithout;
    int withoutNode = max(leftWith, leftWithout) + max(rightWith, rightWithout);

    return {withNode, withoutNode};
}

int maxRob(vector<int>& tree) {
    TreeNode* root = build(tree, 0);
    auto [withRoot, withoutRoot] = robHelper(root);
    return max(withRoot, withoutRoot);
}

int main() {
    vector<int> t1 = {3, 2, 3, -1, 3, -1, 1};
    cout << maxRob(t1) << endl; // 7

    vector<int> t2 = {3, 4, 5, 1, 3, -1, 1};
    cout << maxRob(t2) << endl; // 9

    vector<int> t3 = {10};
    cout << maxRob(t3) << endl; // 10

    return 0;
}
