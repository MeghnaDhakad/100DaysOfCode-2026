import java.util.*;

public class Question2 {

    public static int minRooms(int[][] intervals) {
        int n = intervals.length;

        int[] start = new int[n];
        int[] end = new int[n];

        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        Arrays.sort(start);
        Arrays.sort(end);

        int rooms = 0, j = 0;

        for (int i = 0; i < n; i++) {
            if (start[i] < end[j]) {
                rooms++;       
            } else {
                j++;          
            }
        }

        return rooms;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 5}, {2, 6}, {4, 8}, {9, 10}};

        System.out.println(minRooms(intervals)); 
        
    }
}