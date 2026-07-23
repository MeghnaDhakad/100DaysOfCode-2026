
import java.util.*;
class MCR{
    public static void main(String[] args) {
        int[][] intervals = {{1, 5}, {2, 6}, {4, 8}, {9, 10}
        };
        int n = intervals.length;
        int[] start = new int[n];
        int[] end = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int i = 0;
        int j = 0;
        int rooms = 0;
        int maxRooms = 0;
        while (i < n) {
            if (start[i] < end[j]) {
                rooms++;
                i++;
                maxRooms = Math.max(maxRooms, rooms);
            }
            else {
                rooms--;
                j++;
            }
        }
        System.out.println("Minimum Conference Rooms Required:" + maxRooms);
    }
}