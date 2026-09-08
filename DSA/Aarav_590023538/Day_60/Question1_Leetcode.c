#include <stdio.h>
#include <stdlib.h>

python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: 'TreeNode') -> int:
        self.diameter = 0

        def height(node):
            if not node:
                return 0
            left_h = height(node.left)
            right_h = height(node.right)
            # update diameter using this node as the "peak"
            self.diameter = max(self.diameter, left_h + right_h)
            # return height of subtree rooted at node
            return 1 + max(left_h, right_h)

        height(root)
        return self.diameter

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
