class Solution {
    public double fractionalKnapsack(int[] v, int[] w, int c) {
        int n = v.length;
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) a[i] = i;
        Arrays.sort(a, (i, j) -> Integer.compare(v[j] * w[i], v[i] * w[j]));
        double r = 0;
        for (int i : a) {
            if (c >= w[i]) { r += v[i]; c -= w[i]; } 
            else { r += (double) v[i] * c / w[i]; break; }
        } return r;
    }
}