#include <stdio.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int totalTime = 0;
    
    for (int i = 0; i < ticketsSize; i++) {
        if (i <= k) {
            totalTime += (tickets[i] < tickets[k]) ? tickets[i] : tickets[k];
        } else {
            totalTime += (tickets[i] < tickets[k] - 1) ? tickets[i] : tickets[k] - 1;
        }
    }
    
    return totalTime;
}

int main() {
    int tickets1[] = {2, 3, 2};
    int size1 = sizeof(tickets1) / sizeof(tickets1[0]);
    int k1 = 2;
    printf("Example 1 Output: %d\n", timeRequiredToBuy(tickets1, size1, k1));

    int tickets2[] = {5, 1, 1, 1};
    int size2 = sizeof(tickets2) / sizeof(tickets2[0]);
    int k2 = 0;
    printf("Example 2 Output: %d\n", timeRequiredToBuy(tickets2, size2, k2));

    return 0;
}