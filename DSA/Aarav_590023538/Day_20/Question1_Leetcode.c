#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create an extra node to handle deletion of the head node easily
    struct ListNode start;
    start.next = head;
    // Pointer to traverse the list
    struct ListNode *current = &start;
    // Traverse the linked list
    while (current->next != NULL) {
        // If the next node contains the value to be removed
        if (current->next->val == val) {
            struct ListNode *temp = current->next;  // Node to delete
            current->next = temp->next;             // Skip the node
            free(temp);                             // Free memory
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    // Return the updated head
    return start.next;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
