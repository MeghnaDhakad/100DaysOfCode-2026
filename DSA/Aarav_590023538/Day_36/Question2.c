#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int visited;
} Person;

int ticketMinute(int n, int k) {
    int capacity = n;
    Person *queue = (Person *)malloc(capacity * sizeof(Person));

    // Initialize queue with people numbered 1 to n
    for (int i = 0; i < n; i++) {
        queue[i].id = i + 1;
        queue[i].visited = 0;
    }

    int front = 0, rear = n - 1, size = n;
    int minute = 0, result = -1;
    int firstServe = 1;

    while (size > 0) {
        Person p = queue[front];

        if (firstServe) {
            // First person is always served unconditionally
            front = (front + 1) % capacity;
            size--;
            minute++;
            if (p.id == k) { result = minute; break; }
            firstServe = 0;
            continue;
        }

        if (p.id % 2 == 0 || p.visited || size == 1) {
            // Serve this person
            front = (front + 1) % capacity;
            size--;
            minute++;
            if (p.id == k) { result = minute; break; }
        } else {
            // Odd and not yet skipped -> move to back
            front = (front + 1) % capacity;
            p.visited = 1;
            rear = (rear + 1) % capacity;
            queue[rear] = p;
        }
    }

    free(queue);
    return result;
}

int main() {
    int n, k;
    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);
    printf("Person %d is served at minute %d\n", k, ticketMinute(n, k));
    return 0;
}
