int arrayPairSum(int* nums, int numsSize) {
    int i, j, temp;
    int sum = 0;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    for (i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    return sum;
}