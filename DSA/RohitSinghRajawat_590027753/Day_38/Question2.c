#include <stdio.h>

#define MAX 100

int main()
{
    int n = 4;

    int deque[MAX];
    int front = MAX / 2;
    int rear = MAX / 2 - 1;

    for(int i = n; i >= 1; i--)
    {
        if(front <= rear)
        {
            int last = deque[rear--];
            deque[--front] = last;
        }

        deque[--front] = i;
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", deque[i]);
    }

    return 0;
}