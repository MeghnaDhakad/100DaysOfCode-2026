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

struct Info {
    bool isBST;
    long long minVal, maxVal;
    int size;
};

Info largestBSTHelper(Node* root, int& best) {
    if (!root) {
        return {true, LLONG_MAX, LLONG_MIN, 0};
    }
    Info left = largestBSTHelper(root->left, best);
    Info right = largestBSTHelper(root->right, best);

    if (left.isBST && right.isBST &&
        root->val > left.maxVal && root->val < right.minVal) {
        int size = left.size + right.size + 1;
        best = max(best, size);
        return {true, min((long long)root->val, left.minVal),
                max((long long)root->val, right.maxVal), size};
    }
    return {false, 0, 0, 0};
}

int largestBSTSubtree(Node* root) {
    int best = 0;
    largestBSTHelper(root, best);
    return best;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        Node* root = buildTree(arr, 1, n);
        cout << largestBSTSubtree(root) << endl;
    }
    return 0;
}
