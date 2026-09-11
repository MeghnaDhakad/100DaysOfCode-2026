package Day_88;

import java.util.Arrays;

public class question1 {
    class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum =0;
        for(int i=0; i<nums.length;i=i+2){
            sum+= nums[i];
        }
        return sum;
    }
}
}
