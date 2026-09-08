#include <stdio.h>
#include <stdlib.h>

python
from collections import deque

class Solution:
    def isCompleteTree(self, root: 'TreeNode') -> bool:
        if not root:
            return True

        queue = deque([root])
        seen_null = False

        while queue:
            node = queue.popleft()
            if node is None:
                seen_null = True
                continue
            if seen_null:
                return False
            queue.append(node.left)
            queue.append(node.right)

        return True

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
