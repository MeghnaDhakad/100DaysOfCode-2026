int[] cardTrick(int n) {
    Deque<Integer> dq = new LinkedList<>();

    for (int i = n; i >= 1; i--) {
        if (!dq.isEmpty())
            dq.addFirst(dq.removeLast());

        dq.addFirst(i);
    }

    int[] ans = new int[n];
    int i = 0;

    while (!dq.isEmpty())
        ans[i++] = dq.removeFirst();

    return ans;
}