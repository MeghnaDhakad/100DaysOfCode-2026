import java.util.Arrays;
import java.util.Scanner;

public class Question2 {
    
    public static double fractionalKnapsack(int[] value, int[] weight, int n, int cap) {
        if (n == 0 || cap == 0) return 0.0;

        double[][] items = new double[n][3];
        for (int i = 0; i < n; i++) {
            items[i][0] = value[i];
            items[i][1] = weight[i];
            items[i][2] = (double) value[i] / weight[i];
        }
        
        Arrays.sort(items, (a, b) -> Double.compare(b[2], a[2]));
        
        double ans = 0.0;
        double rem = cap;
        
        for (int i = 0; i < n; i++) {
            if (rem <= 0) {
                break;
            }
            
            double val = items[i][0];
            double itemWeight = items[i][1];
            
            if (itemWeight <= rem) {
                ans += val;
                rem -= itemWeight;
            }
            else {
                double fraction = rem / itemWeight;
                ans += val * fraction;
                rem = 0;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of items: ");
        int n = sc.nextInt();
        
        int[] value = new int[n];
        System.out.print("Enter the " + n + " values: ");
        for (int i = 0; i < n; i++) {
            value[i] = sc.nextInt();
        }
        
        int[] weight = new int[n];
        System.out.print("Enter the " + n + " weights: ");
        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextInt();
        }
        
        System.out.print("Enter the knapsack capacity: ");
        int capacity = sc.nextInt();
        
        double result = fractionalKnapsack(value, weight, n, capacity);
        
        System.out.printf("Output: ", result);        
        sc.close();
    }
}