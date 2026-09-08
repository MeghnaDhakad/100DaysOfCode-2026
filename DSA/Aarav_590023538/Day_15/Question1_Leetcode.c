#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    // Pointers for the head of merged list and current node
    struct ListNode *head = NULL, *temp = NULL;

    // If both lists are non-empty
    if (list1 && list2)
    {
        // Select the smaller node as the head
        if (list1->val > list2->val)
        {
            head = list2;
            list2 = list2->next;
        }
        else
        {
            head = list1;
            list1 = list1->next;
        }

        // temp keeps track of the last node in merged list
        temp = head;

        // Merge the remaining nodes in sorted order
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
        }

        // Attach the remaining nodes of list1 (if any)
        if (list1 != NULL)
        {
            temp->next = list1;
        }

        // Attach the remaining nodes of list2 (if any)
        if (list2 != NULL)
        {
            temp->next = list2;
        }

        // Return the head of the merged list
        return head;
    }
    else
    {
        // If one list is empty, return the other list
        if (list1 != NULL)
            return list1;
        else if (list2 != NULL)
            return list2;
        else
            return NULL;   // Both lists are empty
    }
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
