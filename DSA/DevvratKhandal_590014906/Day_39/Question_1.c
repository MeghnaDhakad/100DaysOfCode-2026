#include <stdio.h>

int timeRequiredToBuy(int tickets[], int n, int k)
{
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            if (tickets[i] < tickets[k])
                time += tickets[i];
            else
                time += tickets[k];
        }
        else
        {
            if (tickets[i] < tickets[k] - 1)
                time += tickets[i];
            else
                time += tickets[k] - 1;
        }
    }

    return time;
}

int main()
{
    int n, k;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int tickets[n];

    printf("Enter number of tickets for each person:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tickets[i]);
    }

    printf("Enter position k: ");
    scanf("%d", &k);

    int result = timeRequiredToBuy(tickets, n, k);

    printf("Time required = %d seconds\n", result);

    return 0;
}