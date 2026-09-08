#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isCompleteTree(struct TreeNode* root) {
    if (!root) return true;
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool nullFound = false;
    while (front < rear) {
        struct TreeNode* curr = queue[front++];
        if (!curr) nullFound = true;
        else {
            if (nullFound) return false;
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }
    return true;
}

int main() {
    struct TreeNode r = {1, NULL, NULL};
    printf("%s\n", isCompleteTree(&r) ? "true" : "false");
    return 0;
}
