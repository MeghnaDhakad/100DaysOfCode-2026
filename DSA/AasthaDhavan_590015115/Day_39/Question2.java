import java.util.*;

public class Question2 {
    static int minRooms(int[][] a) {
        int n = a.length;
        int[] s = new int[n], e = new int[n];

        for (int i = 0; i < n; i++) {
            s[i] = a[i][0];
            e[i] = a[i][1];
        }

        Arrays.sort(s);
        Arrays.sort(e);

        int i = 0, j = 0, rooms = 0, ans = 0;

        while (i < n) {
            if (s[i] < e[j]) {
                rooms++;
                ans = Math.max(ans, rooms);
                i++;
            } else {
                rooms--;
                j++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 5}, {2, 6}, {4, 8}, {9, 10}};
        System.out.println(minRooms(intervals));
    }
}