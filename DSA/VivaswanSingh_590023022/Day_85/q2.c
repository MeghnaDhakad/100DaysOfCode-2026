#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Activity;

int compare(const void *a, const void *b)
{
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;

    return x->end - y->end;
}

int maxActivities(int n, int start[], int end[])
{
    Activity activities[n];

    for (int i = 0; i < n; i++)
    {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    qsort(activities, n, sizeof(Activity), compare);

    int count = 1;
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= lastEnd)
        {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main()
{
    int n = 6;

    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    printf("%d\n", maxActivities(n, start, end));

    return 0;
}