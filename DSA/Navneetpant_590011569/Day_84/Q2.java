class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        int second = intervals[0][1];
        int counter = 0;

        for (int i = 1; i < intervals.length; i++) {
            int[] arr = intervals[i];

            if (arr[0] >= second) {
                second = arr[1];
           
            }
            else {
                counter++;
            }
        }

        return counter;
    }
}