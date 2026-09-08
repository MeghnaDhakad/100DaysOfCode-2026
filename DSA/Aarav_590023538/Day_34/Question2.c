#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], n;
    int stack[MAX], top = -1;
    int left[MAX], right[MAX];

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter heights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find nearest greater or equal element on the left
    top = -1;
    for (int i = 0; i < n; i++) {
        // Remove all smaller heights
        while (top != -1 && arr[stack[top]] < arr[i])
            top--;
        // Store index of nearest greater/equal element
        if (top == -1)
            left[i] = -1;
        else
            left[i] = stack[top];
        // Push current index
        stack[++top] = i;
    }

    // Find nearest greater or equal element on the right
    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        // Remove all smaller heights
        while (top != -1 && arr[stack[top]] < arr[i])
            top--;
        // Store index of nearest greater/equal element
        if (top == -1)
            right[i] = n;
        else
            right[i] = stack[top];
        // Push current index
        stack[++top] = i;
    }

    int maxVisible = 0;
    // Calculate visible people for every person
    for (int i = 0; i < n; i++) {
        // People visible on the left
        int leftCount = i - left[i] - 1;
        // People visible on the right
        int rightCount = right[i] - i - 1;
        // Include the person themselves
        int total = leftCount + rightCount + 1;
        if (total > maxVisible)
            maxVisible = total;
    }

    printf("Maximum people visible = %d\n", maxVisible);
    return 0;
}
