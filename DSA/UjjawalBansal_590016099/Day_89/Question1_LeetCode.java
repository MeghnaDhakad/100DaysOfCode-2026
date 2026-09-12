public class Question1_LeetCode {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int i = 0;
        while (i < flowerbed.length && n > 0) {
            if (flowerbed[i] == 1) i += 2;
            else {
                if (i != 0 && flowerbed[i-1] == 1) i++;
                else if (i != flowerbed.length - 1 && flowerbed[i+1] == 1) i+=3;
                else {
                    i += 2;
                    n--;
                }
            }
        }
        return n == 0;
    }
}
