int minRooms(int[][] intervals) {
    Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

    PriorityQueue<Integer> pq = new PriorityQueue<>();

    for (int[] x : intervals) {
        if (!pq.isEmpty() && pq.peek() <= x[0])
            pq.poll();

        pq.offer(x[1]);
    }

    return pq.size();
}