#include <stdio.h>
#include <stdlib.h>

int countAuditIssues(int* scores, int n, int threshold) {
    int count = 0;
    for (int i = 0; i < n; i++) if (scores[i] < threshold) count++;
    return count;
}

int main() {
    int s[] = {80, 45, 90, 60, 30};
    printf("%d\n", countAuditIssues(s, 5, 50));
    return 0;
}
