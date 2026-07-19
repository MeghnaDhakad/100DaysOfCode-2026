#include <stdio.h>

void nextGreaterElement(int arr[], int n, int ans[]) {
    for (int i = 0; i < n; i++) {
        ans[i] = -1;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }
}

int main() {
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans[n];

    nextGreaterElement(arr, n, ans);

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i != n - 1)
            printf(",");
    }
    printf("]\n");

    return 0;
}
