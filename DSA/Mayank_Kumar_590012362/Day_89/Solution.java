public class Solution {
    public int buyChoco(int[] p, int m) {
        int a = Integer.MAX_VALUE, b = Integer.MAX_VALUE;
        for (int x : p) {
            if (x < a) {
                b = a;
                a = x;
            } else if (x < b) {
                b = x;
            }
        } return m >= a + b ? m - a - b : m;
    }
}
