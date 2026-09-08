#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to check whether the linked list contains a cycle
int hasCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    // Traverse the linked list
    while (fast != NULL && fast->next != NULL) {
        // Move slow pointer one step
        slow = slow->next;
        // Move fast pointer two steps
        fast = fast->next->next;
        // If both pointers meet, a cycle exists
        if (slow == fast) {
            return 1;
        }
    }
    // No cycle found
    return 0;
}

int main() {
    struct Node *head = NULL;
    // Create linked list here
    // (Input code can be added as per requirement)
    if (hasCycle(head))
        printf("Cycle exists\n");
    else
        printf("No cycle exists\n");
    return 0;
}
