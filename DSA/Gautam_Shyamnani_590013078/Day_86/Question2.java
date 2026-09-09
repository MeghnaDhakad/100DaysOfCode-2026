import java.util.*;

public class Question2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long[] value = new long[n];
        long[] weight = new long[n];

        for (int i = 0; i < n; i++) {
            value[i] = sc.nextLong();
        }

        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextLong();
        }

        long capacity = sc.nextLong();

        double[][] items = new double[n][2];

        for (int i = 0; i < n; i++) {
            items[i][0] = value[i];
            items[i][1] = weight[i];
        }

        Arrays.sort(items, (a, b) ->
            Double.compare(b[0] / b[1], a[0] / a[1])
        );

        double answer = 0;

        for (int i = 0; i < n; i++) {

            if (capacity >= items[i][1]) {
                answer += items[i][0];
                capacity -= (long) items[i][1];
            } else {
                answer += (items[i][0] / items[i][1]) * capacity;
                break;
            }
        }

        if (answer == (long) answer) {
            System.out.println((long) answer);
        } else {
            System.out.println(answer);
        }

        sc.close();
    }
}