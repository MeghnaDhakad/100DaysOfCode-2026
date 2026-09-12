public class Question1_leetcode {

        // Function to check if n flowers can be planted
    static boolean canPlaceFlowers(int[] flowerbed, int n) {

        // Go through every position in the flowerbed
        for (int i = 0; i < flowerbed.length; i++) {

            // Check if the current position is empty
            if (flowerbed[i] == 0) {

                // Check the left side
                //
                // If i == 0, there is no left position,
                // so it is considered empty.
                boolean leftEmpty = (i == 0 || flowerbed[i - 1] == 0);

                // Check the right side
                //
                // If i is the last position, there is no
                // right position, so it is considered empty.
                boolean rightEmpty =
                        (i == flowerbed.length - 1 || flowerbed[i + 1] == 0);

                // We can plant a flower only if
                // both left and right sides are empty
                if (leftEmpty && rightEmpty) {

                    // Plant the flower
                    flowerbed[i] = 1;

                    // One flower has been planted
                    n--;

                    // If we have planted all required flowers,
                    // we can immediately return true
                    if (n == 0) {
                        return true;
                    }
                }
            }
        }

        // If n became 0, all flowers were planted
        return n <= 0;
    }


}
