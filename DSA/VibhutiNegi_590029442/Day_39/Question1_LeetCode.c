typedef struct {
    int index;
    int tickets;
} Person;
int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
     Person queue[10000];
    int front = 0, rear = 0;
    for (int i = 0; i < ticketsSize; i++) {
        queue[rear].index = i;
        queue[rear].tickets = tickets[i];
        rear++;
    }
    int time = 0;
    while (front < rear) {
        Person p = queue[front];
        front++;
        p.tickets--;
        time++;
        if (p.index == k && p.tickets == 0)
            return time;
        if (p.tickets > 0) {
            queue[rear] = p;
            rear++;
        }
    }
    return time;
}