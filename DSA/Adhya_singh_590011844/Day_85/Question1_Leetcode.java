import java.util.*;

public class Main {

    static int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int child = 0;
        int cookie = 0;

        while (child < g.length && cookie < s.length) {

            if (s[cookie] >= g[child]) {

                child++;
            }

            cookie++;
        }

        return child;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] g = new int[n];

        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }

        int m = sc.nextInt();
        int[] s = new int[m];

        for (int i = 0; i < m; i++) {
            s[i] = sc.nextInt();
        }

        System.out.println(findContentChildren(g, s));

        sc.close();
    }
}