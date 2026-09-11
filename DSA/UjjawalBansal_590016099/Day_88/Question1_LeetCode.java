public class Question1_LeetCode {
    public int arrayPairSum(int[] nums) {
        int[] arr = new int[20001];
        for (int num : nums) {
            arr[num + 10000]++;
        }
        int ans = 0;
        boolean a = true;
        
        for (int i = 0; i <= 20000; i++) {
            while (arr[i] > 0) {
                if (a) {
                    ans += (i - 10000);
                }
                a = !a;
                arr[i]--;
            }
        }
        
        return ans;
    }
}
