import java.util.*;

class Solution {
    static int maxActivities(int[] s, int[] e) {
        int n = s.length;
        int[][] a = new int[n][2];

        for (int i = 0; i < n; i++) {
            a[i][0] = e[i];
            a[i][1] = s[i];
        }

        Arrays.sort(a, Comparator.comparingInt(x -> x[0]));

        int c = 0, x = -1;

        for (int[] v : a) {
            if (v[1] >= x) {
                c++;
                x = v[0];
            }
        }

        return c;
    }
}