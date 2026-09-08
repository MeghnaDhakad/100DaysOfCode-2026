#include <stdio.h>
#include <stdlib.h>

pp
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node && node->left == nullptr && node->right == nullptr;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int sum = 0;

        if (isLeaf(root->left))
            sum += root->left->val;

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
