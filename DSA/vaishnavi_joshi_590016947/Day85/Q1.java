import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        
        // Sort greed factors and cookie sizes
        Arrays.sort(g);
        Arrays.sort(s);

        int child = 0;
        int cookie = 0;

        // Try to satisfy children
        while (child < g.length && cookie < s.length) {

            if (s[cookie] >= g[child]) {
                // Cookie can satisfy this child
                child++;
                cookie++;
            } else {
                // Cookie is too small, try next cookie
                cookie++;
            }
        }

        return child;
    }
}