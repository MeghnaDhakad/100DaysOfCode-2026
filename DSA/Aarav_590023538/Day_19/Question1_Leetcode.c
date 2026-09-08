#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a singly linked list node.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Start traversing from the head of the linked list
    struct ListNode* curr = head;
    // Traverse until the end of the list
    while (curr != NULL && curr->next != NULL) {
        // If the current node and next node have the same value,
        // remove the duplicate node by skipping it
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        }
        // Otherwise, move to the next node
        else {
            curr = curr->next;
        }
    }
    // Return the head of the updated linked list
    return head;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
