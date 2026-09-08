#include <stdio.h>
#include <stdlib.h>

typedef struct { int val; int index; } Element;
int compareVal(const void* a, const void* b) { return ((Element*)b)->val - ((Element*)a)->val; }
int compareIndex(const void* a, const void* b) { return ((Element*)a)->index - ((Element*)b)->index; }

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) { arr[i].val = nums[i]; arr[i].index = i; }
    qsort(arr, numsSize, sizeof(Element), compareVal);
    qsort(arr, k, sizeof(Element), compareIndex);
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) res[i] = arr[i].val;
    free(arr);
    *returnSize = k;
    return res;
}

int main() {
    int nums[] = {2, 1, 3, 3};
    int k = 2, sz;
    int* res = maxSubsequence(nums, 4, k, &sz);
    for (int i = 0; i < sz; i++) printf("%d ", res[i]);
    printf("\n");
    free(res);
    return 0;
}
