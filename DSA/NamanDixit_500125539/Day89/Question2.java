import java.util.Scanner;
import java.util.Arrays;

public class Question2 {

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

    public static void main(String[] args) {

        // Scanner is used to take input from the user
        Scanner sc = new Scanner(System.in);

        // Ask the user for the size of the array
        // The size must be even because
        // the elements are divided into pairs.
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        // Create the array
        int[] nums = new int[n];

        // Take array elements from the user
        System.out.println("Enter the array elements:");

        for (int i = 0; i < n; i++) {

            // Store each number in the array
            nums[i] = sc.nextInt();
        }

        // Find the maximum sum
        int result = arrayPairSum(nums);

        // Print the answer
        System.out.println("Maximum sum = " + result);

        // Close Scanner
        sc.close();
    }
}