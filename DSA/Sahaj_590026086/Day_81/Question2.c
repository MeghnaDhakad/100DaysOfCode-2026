#include <stdio.h>
#include <stdlib.h>

int findUnique(int* arr, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) res ^= arr[i];
    return res;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 4};
    printf("%d\n", findUnique(arr, 7));
    return 0;
}
