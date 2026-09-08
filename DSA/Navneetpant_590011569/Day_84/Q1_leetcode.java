class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int cookies = 0;
        int child = 0;

        while (cookies < s.length && child < g.length) {
            if (g[child] <= s[cookies]) {
                child ++;
                cookies ++;
            }
            else {
                cookies++;
            }
        }
        return child;

    }
}