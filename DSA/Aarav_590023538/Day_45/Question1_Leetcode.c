java
class Solution {
    public int searchInsert(int[] nums, int t) {
        int l = 0, r = nums.length - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] == t) {
                return m;
            } else if (nums[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l;
    }
    
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.searchInsert(new int[]{1,3,5,6}, 5)); // 2
        System.out.println(s.searchInsert(new int[]{1,3,5,6}, 2)); // 1
        System.out.println(s.searchInsert(new int[]{1,3,5,6}, 7)); // 4
    }
}
