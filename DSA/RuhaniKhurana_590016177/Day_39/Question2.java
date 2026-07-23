class Solution {

    public int minMeetingRooms(int[][] intervals) {

        int n = intervals.length;

        int[] s = new int[n];
        int[] e = new int[n];

        for (int i = 0; i < n; i++) {
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }

        Arrays.sort(s);
        Arrays.sort(e);

        int r = 0;
        int endPointer = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] < e[endPointer]) {
                r++;
            } else {
                endPointer++;
            }
        }

        return r;
    }
}