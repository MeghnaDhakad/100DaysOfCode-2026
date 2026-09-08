#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
} Activity;
int compare(const void *a, const void *b) {
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;
    return x->end - y->end;
}
int main() {
    int n;
    scanf("%d", &n);
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].end);
    }
    qsort(activities, n, sizeof(Activity), compare);
    int count = 0;
    int lastEnd = -1;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    printf("%d\n", count);
    return 0;
}