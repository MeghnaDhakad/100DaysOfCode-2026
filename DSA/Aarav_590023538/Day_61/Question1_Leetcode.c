#include <stdio.h>
#include <stdlib.h>

int findJudge(int n, int trust[][2], int trustSize) {
    int *score = calloc(n + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0], b = trust[i][1];
        score[a]--; // a trusts someone -> not a candidate judge
        score[b]++; // b is trusted by someone
    }

    int judge = -1;
    for (int i = 1; i <= n; i++) {
        if (score[i] == n - 1) { judge = i; break; }
    }

    free(score);
    return judge;
}

int main(void) {
    int t1[][2] = {{1,2}};
    printf("%d\n", findJudge(2, t1, 1)); // 2

    int t2[][2] = {{1,3},{2,3}};
    printf("%d\n", findJudge(3, t2, 2)); // 3

    int t3[][2] = {{1,3},{2,3},{3,1}};
    printf("%d\n", findJudge(3, t3, 3)); // -1

    return 0;
}
