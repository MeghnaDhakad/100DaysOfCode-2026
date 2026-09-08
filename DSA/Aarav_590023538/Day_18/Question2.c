#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to remove the nth node from the end
struct Node* removeNthFromEnd(struct Node *head, int n) {
    // Create a temporary node to handle deletion of the head node
    struct Node *tempHead = (struct Node *)malloc(sizeof(struct Node));
    tempHead->next = head;
    struct Node *fast = tempHead;
    struct Node *slow = tempHead;
    // Move the fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    // Delete the required node
    struct Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);
    head = tempHead->next;
    free(tempHead);
    return head;
}

// Function to print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n;
    // Input and linked list creation can be coded here as per the required input format.
    scanf("%d", &n);
    head = removeNthFromEnd(head, n);
    printList(head);
    return 0;
}
