#include <stdio.h>
#include <stdlib.h>

python
# Optimized O(n) approach
def time_required_to_buy(tickets, k):
    time = 0
    for i, t in enumerate(tickets):
        if i <= k:
            time += min(t, tickets[k])
        else:
            time += min(t, tickets[k] - 1)
    return time

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
