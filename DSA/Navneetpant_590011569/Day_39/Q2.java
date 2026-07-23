class Solution {
    public int minMeetingRooms(int[][] intervals) {

        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int[] meeting : intervals) {
            if (!pq.isEmpty() && meeting[0] >= pq.peek()) {
                pq.poll();
            }

            pq.offer(meeting[1]);
        }

        return pq.size();
    }
}