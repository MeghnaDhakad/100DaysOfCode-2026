#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int intervals[][2], int n)
{
    int start[100];
    int end[100];

    for(int i = 0; i < n; i++)
    {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0;
    int j = 0;
    int rooms = 0;
    int maxRooms = 0;

    while(i < n)
    {
        if(start[i] < end[j])
        {
            rooms++;

            if(rooms > maxRooms)
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
    int intervals[][2] = {{1,5},{2,6},{4,8},{9,10}};
    int n = 4;

    printf("%d", minMeetingRooms(intervals, n));

    return 0;
}