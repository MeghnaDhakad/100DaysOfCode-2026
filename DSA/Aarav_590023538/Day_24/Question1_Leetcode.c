#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Function to calculate the sum of the squares of digits
int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;          // Extract the last digit
        sum += digit * digit;        // Add its square
        n /= 10;                     // Remove the last digit
    }
    return sum;
}

bool isHappy(int n) {
    // Floyd's Cycle Detection (Slow & Fast Pointers)
    int slow = n;
    int fast = n;

    do {
        // Move slow pointer one step
        slow = getNext(slow);
        // Move fast pointer two steps
        fast = getNext(getNext(fast));
    } while (slow != fast);

    // If the cycle ends at 1, the number is happy
    return slow == 1;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
