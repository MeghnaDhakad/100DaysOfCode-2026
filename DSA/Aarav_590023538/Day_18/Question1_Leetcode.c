#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    // Find the length of the linked list
    int len = 1;
    struct ListNode *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }
    // Reduce unnecessary rotations
    k = k % len;
    if (k == 0)
        return head;
    // Make the linked list circular
    tail->next = head;
    // Find the new tail
    int steps = len - k;
    struct ListNode *newTail = head;
    while (--steps) {
        newTail = newTail->next;
    }
    // Set the new head
    struct ListNode *newHead = newTail->next;
    // Break the circular link
    newTail->next = NULL;
    return newHead;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
