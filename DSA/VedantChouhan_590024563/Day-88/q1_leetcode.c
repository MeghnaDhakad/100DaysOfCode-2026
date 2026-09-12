#include <stdio.h>

int canPlaceFlowers(int flowerbed[], int flowerbedSize, int n) {
    int count = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {

            int left = (i == 0) ? 0 : flowerbed[i - 1];
            int right = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];

            if (left == 0 && right == 0) {
                flowerbed[i] = 1;
                count++;

                if (count >= n)
                    return 1;
            }
        }
    }

    return count >= n;
}

int main() {
    int size, n;

    printf("Enter flowerbed size: ");
    scanf("%d", &size);

    int flowerbed[size];

    printf("Enter flowerbed elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &flowerbed[i]);
    }

    printf("Enter number of flowers to plant: ");
    scanf("%d", &n);

    if (canPlaceFlowers(flowerbed, size, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}