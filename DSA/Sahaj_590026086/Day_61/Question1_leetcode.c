#include <stdio.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* score = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < trustSize; i++) {
        score[trust[i][0]]--;
        score[trust[i][1]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (score[i] == n - 1) { free(score); return i; }
    }
    free(score);
    return -1;
}

int main() {
    int t1[] = {1, 2};
    int* trust[] = {t1};
    int colSize = 2;
    printf("%d\n", findJudge(2, trust, 1, &colSize));
    return 0;
}
