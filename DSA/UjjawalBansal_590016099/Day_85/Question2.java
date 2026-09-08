import java.util.Arrays;
import java.util.Scanner;

public class Question2 {
    
    public static int maxActivities(int[] start, int[] end, int n) {
        if (n == 0) return 0;
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i][0] = start[i];
            activities[i][1] = end[i];
        }
        
        Arrays.sort(activities, (a, b) -> Integer.compare(a[1], b[1]));
        
        int count = 1;
        int lastEndTime = activities[0][1];
        
        for (int i = 1; i < n; i++) {
            if (activities[i][0] >= lastEndTime) {
                count++;
                lastEndTime = activities[i][1];
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of activities: ");
        int n = sc.nextInt();
        
        int[] start = new int[n];
        System.out.print("Enter the " + n + " start times: ");
        for (int i = 0; i < n; i++) {
            start[i] = sc.nextInt();
        }
        
        int[] end = new int[n];
        System.out.print("Enter the " + n + " end times: ");
        for (int i = 0; i < n; i++) {
            end[i] = sc.nextInt();
        }
        
        int result = maxActivities(start, end, n);
        System.out.println(result);
        sc.close();
    }
}