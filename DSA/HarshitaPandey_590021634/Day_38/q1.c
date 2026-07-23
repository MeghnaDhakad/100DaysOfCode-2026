/* Q1: Given n, reconstruct the initial deck arrangement such that revealing the top card 
and moving the next to the bottom repeatedly produces cards in order 1 to n.

Example:
Input: n = 4; Output: [1, 3, 2, 4]    */


#include <stdio.h>
#define MAX 100

int queue[MAX*2];
int front=0, rear=0;

void enqueue(int value)
{
    queue[rear++]= value;

}


int dequeue()
{
    return queue[front++];

}

int isempty()
{
    return front == rear;
}


int main()
{
    int n,i;

    printf("enter n: ");
    scanf("%d", &n);

    int cards[n];

    for (i=0; i<n; i++)
    {
        enqueue(i);
    }

    
    int val=1;
    while (!isempty())
    {
        int index= dequeue();
        cards[index] = val++;

        if (!isempty())
        {
            int next = dequeue();
            enqueue(next);
        }
    }

    for (int i=0; i<n; i++)
    {
        printf("%d, ", cards[i]);
    }

    return 0;
}