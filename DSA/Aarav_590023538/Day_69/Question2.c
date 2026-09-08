pp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
};

Node* buildTree(vector<long long>& arr, int i, int n) {
    if (i > n || i < 1 || arr[i] == -1) return nullptr;
    Node* node = new Node{arr[i], nullptr, nullptr};
    node->left = buildTree(arr, 2 * i, n);
    node->right = buildTree(arr, 2 * i + 1, n);
    return node;
}

// Splits root into (lessThanK, geqK) using standard BST split
pair<Node*, Node*> split(Node* root, long long K) {
    if (!root) return {nullptr, nullptr};
    if (root->val < K) {
        auto [l, r] = split(root->right, K);
        root->right = l;
        return {root, r};
    } else {
        auto [l, r] = split(root->left, K);
        root->left = r;
        return {l, root};
    }
}

void preorder(Node* root, vector<long long>& out) {
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}

void printBranch(Node* root) {
    vector<long long> out;
    preorder(root, out);
    if (out.empty()) {
        cout << "EMPTY\n";
        return;
    }
    for (size_t i = 0; i < out.size(); i++) {
        cout << out[i] << (i + 1 < out.size() ? ' ' : '\n');
    }
}

int main() {
    int n;
    long long K;
    cin >> n;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> K;

    Node* root = buildTree(arr, 1, n);
    auto [branchA, branchB] = split(root, K);

    printBranch(branchA);
    printBranch(branchB);
    return 0;
}
