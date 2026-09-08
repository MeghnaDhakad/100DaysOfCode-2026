#include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to find the middle node
struct Node* findMiddle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    // Move slow by one step and fast by two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Slow will point to the middle node
    return slow;
}

int main() {
    struct Node *head = NULL;
    /*
        Take input as per your requirement.
        Example:
        Input:
        5
        1 2 3 4 5
        or create the linked list manually.
    */
    struct Node *middle = findMiddle(head);
    if (middle != NULL)
        printf("%d\n", middle->data);
    else
        printf("Linked list is empty.\n");
    return 0;
}
