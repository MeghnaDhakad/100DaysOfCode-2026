class Solution {
    public int minCoins(int[] c, int a) {
        Arrays.sort(c);
        int n = c.length, r = 0;
        for (int i = n - 1; i >= 0 && a > 0; i--) {
            r += a / c[i];
            a %= c[i];
        }
        return a == 0 ? r : -1;
    }
}