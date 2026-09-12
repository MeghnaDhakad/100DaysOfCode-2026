import java.util.*;

public class Main {

    static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;

        for (int i = 0; i < flowerbed.length; i++) {

            if (flowerbed[i] == 0
                    && (i == 0 || flowerbed[i - 1] == 0)
                    && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                count++;

                if (count >= n) {
                    return true;
                }
            }
        }

        return count >= n;
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