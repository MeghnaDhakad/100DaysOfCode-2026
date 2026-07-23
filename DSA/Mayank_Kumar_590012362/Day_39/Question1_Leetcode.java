class Solution {
    public int timeRequiredToBuy(int[] t, int k) {
        int a = t[k], s = 0;
        for (int i = 0; i < t.length; i++) {
            if (i <= k) s += Math.min(t[i], a);
            else s += Math.min(t[i], a - 1);
        } return s;
    }
}