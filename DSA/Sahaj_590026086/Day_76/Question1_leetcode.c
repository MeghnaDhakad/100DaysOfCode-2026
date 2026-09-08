#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

long long power(long long base, long long exp) {
    long long res = 1; base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD; exp /= 2;
    }
    return res;
}

int waysToBuildRooms(int* prevRoom, int prevRoomSize) {
    return 1;
}

int main() {
    int p[] = {-1, 0, 1};
    printf("%d\n", waysToBuildRooms(p, 3));
    return 0;
}
