bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {

            int left = (i == 0 || flowerbed[i - 1] == 0);
            int right = (i == flowerbedSize - 1 || flowerbed[i + 1] == 0);

            if (left && right) {
                flowerbed[i] = 1;
                count++;

                if (count >= n)
                    return true;
            }
        }
    }

    return count >= n;
}