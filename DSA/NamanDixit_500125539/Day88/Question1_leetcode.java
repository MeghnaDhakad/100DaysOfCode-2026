class Question1_leetcode {
       // Function to find the maximum sum
    // of the minimum values of each pair
    static int arrayPairSum(int[] nums) {

        // Sort the array from smallest to largest
        Arrays.sort(nums);

        // This will store our answer
        int sum = 0;

        // Take every second element
        //
        // After sorting:
        // nums[0] and nums[1] form a pair
        // nums[2] and nums[3] form a pair
        // nums[4] and nums[5] form a pair
        // and so on...
        for (int i = 0; i < nums.length; i = i + 2) {

            // The first element of every pair
            // is the smaller element.
            //
            // So add it to the answer.
            sum = sum + nums[i];
        }

        // Return the maximum sum
        return sum;
    }
}