#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    // Reverse the links
    while (curr != NULL) {
        // Store the next node
        next = curr->next;
        // Reverse the current node's link
        curr->next = prev;
        // Move all pointers one step forward
        prev = curr;
        curr = next;
    }

    // prev becomes the new head
    return prev;
}

// Function to print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Driver code
int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    printf("Original List: ");
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    printf("\nReversed List: ");
    printList(head);

    return 0;
}
