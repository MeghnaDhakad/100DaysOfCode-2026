import java.util.*;

public class Question1_Leetcode {

    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int planted = 0;

        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0) {
                int left = (i == 0) ? 0 : flowerbed[i - 1];
                int right = (i == flowerbed.length - 1) ? 0 : flowerbed[i + 1];

                if (left == 0 && right == 0) {
                    flowerbed[i] = 1;
                    planted++;

                    if (planted >= n) {
                        return true;
                    }
                }
            }
        }

        return planted >= n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int size = sc.nextInt();
        int[] flowerbed = new int[size];

        for (int i = 0; i < size; i++) {
            flowerbed[i] = sc.nextInt();
        }

        int n = sc.nextInt();

        System.out.println(canPlaceFlowers(flowerbed, n));

        sc.close();
    }
}