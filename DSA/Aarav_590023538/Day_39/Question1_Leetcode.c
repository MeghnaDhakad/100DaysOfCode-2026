#include <stdio.h>
#include <stdlib.h>

python
# Simple simulation approach - O(n * max_tickets)
def time_required_to_buy(tickets, k):
    time = 0
    i = 0
    n = len(tickets)
    while tickets[k] > 0:
        if tickets[i] > 0:
            tickets[i] -= 1
            time += 1
        i = (i + 1) % n
    return time

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
