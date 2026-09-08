#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only one node, no swapping is needed
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // Initialize pointers for adjacent nodes
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    // Traverse the list two nodes at a time
    while (fast != NULL) {
        // Swap the values of the adjacent nodes
        int temp = fast->val;
        fast->val = slow->val;
        slow->val = temp;
        // Move slow to the next pair
        slow = fast->next;
        // Check if another pair exists
        if (fast->next == NULL) {
            fast = NULL;
        }
        else {
            // Move fast to the second node of the next pair
            fast = fast->next->next;
        }
    }
    // Return the modified linked list
    return head;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
