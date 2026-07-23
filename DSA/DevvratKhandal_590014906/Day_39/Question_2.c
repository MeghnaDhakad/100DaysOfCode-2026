#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int start[], int end[], int n)
{
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0;
    int j = 0;

    int rooms = 0;
    int maxRooms = 0;

    while (i < n)
    {
        if (start[i] < end[j])
        {
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main()
{
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start and end time of each meeting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Meeting %d: ", i + 1);
        scanf("%d %d", &start[i], &end[i]);
    }

    int result = minMeetingRooms(start, end, n);

    printf("Minimum conference rooms required = %d\n", result);

    return 0;
}