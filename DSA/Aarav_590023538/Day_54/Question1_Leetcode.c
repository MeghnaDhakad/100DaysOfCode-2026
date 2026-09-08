#include <stdio.h>

int maxFrequencyElements(int *nums, int n) {
    int count[101] = {0}; // values are 1..100

    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
    }

    int maxFreq = 0;
    for (int v = 1; v <= 100; v++) {
        if (count[v] > maxFreq) maxFreq = count[v];
    }

    int total = 0;
    for (int v = 1; v <= 100; v++) {
        if (count[v] == maxFreq) total += count[v];
    }

    return total;
}

int main(void) {
    int n1[] = {1, 2, 2, 3, 1, 4};
    printf("%d\n", maxFrequencyElements(n1, 6)); // 4

    int n2[] = {1, 2, 3, 4, 5};
    printf("%d\n", maxFrequencyElements(n2, 5)); // 5

    return 0;
}
