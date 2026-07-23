int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    int target = tickets[k];

    for (int i = 0; i < ticketsSize; i++) {
        if (i <= k) {
            if (tickets[i] < target)
                time += tickets[i];
            else
                time += target;
        } else {
            if (tickets[i] < target - 1)
                time += tickets[i];
            else
                time += target - 1;
        }
    }

    return time;
}
