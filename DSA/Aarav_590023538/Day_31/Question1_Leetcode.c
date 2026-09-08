#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    // Size of the output array
    *returnSize = pricesSize;
    // Create result array
    int *answer = (int *)malloc(pricesSize * sizeof(int));
    // Copy original prices into answer
    for (int i = 0; i < pricesSize; i++) {
        answer[i] = prices[i];
    }
    // Stack to store indices of prices
    int stack[pricesSize];
    int top = -1;
    // Traverse all prices
    for (int i = 0; i < pricesSize; i++) {
        // If current price is smaller or equal,
        // it becomes the discount for previous items
        while (top != -1 && prices[i] <= prices[stack[top]]) {
            int index = stack[top];
            top--;
            // Apply discount
            answer[index] = prices[index] - prices[i];
        }
        // Push current index into stack
        top++;
        stack[top] = i;
    }
    return answer;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
