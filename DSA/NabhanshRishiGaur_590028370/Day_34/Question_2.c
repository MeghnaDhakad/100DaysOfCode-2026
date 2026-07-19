#include <stdio.h>

int maxVisiblePeople(int arr[], int n) {
    int maxVisible = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;

        for (int j = i - 1; j >= 0; j--) {
            count++;
            if (arr[j] >= arr[i])
                break;
        }

        for (int j = i + 1; j < n; j++) {
            count++;
            if (arr[j] >= arr[i])
                break;
        }

        if (count > maxVisible)
            maxVisible = count;
    }

    return maxVisible;
}

int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxVisiblePeople(arr, n));

    return 0;
}
