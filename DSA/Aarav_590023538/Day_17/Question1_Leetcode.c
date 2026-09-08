#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr != NULL) {
        struct ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    // Empty list or single node is always a palindrome
    if (head == NULL || head->next == NULL)
        return true;
    // Find the middle of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse the second half
    struct ListNode *secondHalf = reverseList(slow);
    // Compare both halves
    struct ListNode *firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
