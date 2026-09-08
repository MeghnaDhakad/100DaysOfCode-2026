import java.util.*;

class Solution {
    public int maxActivities(int[] start, int[] end) {
        int n = start.length;

        Integer[] index = new Integer[n];

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        Arrays.sort(index, (a, b) -> Integer.compare(end[a], end[b]));

        int count = 0;
        int lastEnd = -1;

        for (int i : index) {
            if (start[i] >= lastEnd) {
                count++;
                lastEnd = end[i];
            }
        }

        return count;
    }
}
