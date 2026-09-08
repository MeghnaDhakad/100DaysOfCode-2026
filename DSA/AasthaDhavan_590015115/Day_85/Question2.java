import java.util.*;
class Question2 {
    public static int maxActivities(int[] start, int[] end) {
        int n = start.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (end[i] > end[j]) {
                    int temp = end[i];
                    end[i] = end[j];
                    end[j] = temp;
                    temp = start[i];
                    start[i] = start[j];
                    start[j] = temp;
                }
            }
        }
        int count = 1;
        int lastEnd = end[0];
        for (int i = 1; i < n; i++) {
            if (start[i] >= lastEnd) {
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int n = 6;
        int[] start = {1, 3, 0, 5, 8, 5};
        int[] end = {2, 4, 6, 7, 9, 9};
        System.out.println(maxActivities(start, end));
    }
}