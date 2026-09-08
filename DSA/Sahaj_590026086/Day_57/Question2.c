#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int sumTwinTrees(struct Node* t1, struct Node* t2) {
    if (!t1 || !t2) return 0;
    int match = (t1->val == t2->val) ? t1->val : 0;
    return match + sumTwinTrees(t1->left, t2->left) + sumTwinTrees(t1->right, t2->right);
}

int main() {
    struct Node n1 = {10, NULL, NULL};
    struct Node n2 = {10, NULL, NULL};
    printf("%d\n", sumTwinTrees(&n1, &n2));
    return 0;
}
