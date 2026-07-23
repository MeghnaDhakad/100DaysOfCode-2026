#include <stdio.h>
typedef struct {
    int start;
    int end;
} Meeting;
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void sortMeetings(Meeting m[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j].start > m[j + 1].start) {
                Meeting temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index])
            break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}
void heapifyDown(int heap[], int size) {
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest == i)
            break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}
int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);
    Meeting m[n];
    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &m[i].start, &m[i].end);
    sortMeetings(m, n);
    int heap[100000];
    int size = 0;
    heap[size++] = m[0].end;
    for (int i = 1; i < n; i++) {
        if (m[i].start >= heap[0]) {
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(heap, size);
        }
        heap[size] = m[i].end;
        heapifyUp(heap, size);
        size++;
    }
    printf("Minimum rooms required = %d\n", size);
    return 0;
}