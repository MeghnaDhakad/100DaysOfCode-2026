int jobScheduling(int[] d, int[] p) {
    int n = d.length, a = 0;
    int[][] j = new int[n][2];

    for (int i = 0; i < n; i++) {
        j[i][0] = d[i];
        j[i][1] = p[i];
    }

    Arrays.sort(j, (x, y) -> y[1] - x[1]);

    boolean[] s = new boolean[n + 1];

    for (int[] x : j) {
        for (int k = Math.min(x[0], n); k > 0; k--) {
            if (!s[k]) {
                s[k] = true;
                a += x[1];
                break;
            }
        }
    }

    return a;
}