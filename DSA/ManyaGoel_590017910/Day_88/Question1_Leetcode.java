class Question1_Leetcode {
    public int arrayPairSum(int[] nums) {
        int[] count = new int[20001];
        for (int x : nums) count[x + 10000]++;

        int sum = 0, parity = 0;
        for (int i = 0; i < 20001; i++) {
            while (count[i]-- > 0) {
                if (parity == 0) sum += i - 10000;
                parity ^= 1;
            }
        }
        return sum;
    }
}