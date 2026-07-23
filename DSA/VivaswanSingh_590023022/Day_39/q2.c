#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index)
{
    while (1)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

int minMeetingRooms(int **intervals, int intervalsSize)
{
    if (intervalsSize == 0)
        return 0;

    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int heap[1000];
    int size = 0;

    heap[size++] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] >= heap[0])
        {
            heap[0] = intervals[i][1];
            heapifyDown(heap, size, 0);
        }
        else
        {
            heap[size] = intervals[i][1];
            heapifyUp(heap, size);
            size++;
        }
    }

    return size;
}

int main()
{
    int a[] = {1, 5};
    int b[] = {2, 6};
    int c[] = {4, 8};
    int d[] = {9, 10};

    int *intervals[] = {a, b, c, d};

    printf("%d\n", minMeetingRooms(intervals, 4));

    return 0;
}