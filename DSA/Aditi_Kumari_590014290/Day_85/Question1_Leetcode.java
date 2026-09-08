package DSA.Aditi_Kumari_590014290.Day_85;
import java.util.*;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int child = 0;
        int cookie = 0;

        Arrays.sort(g);
        Arrays.sort(s);

        while (child < g.length && cookie < s.length) {
            if (g[child] > s[cookie]) {
                cookie++;
            } else {
                child++;
                cookie++;
            }
        }

        return child;
    }
}