#include <stdio.h>
#include <stdlib.h>

int countCrabComponents(int n, int m) {
    return n > m ? n - m : 1;
}

int main() {
    printf("%d\n", countCrabComponents(5, 3));
    return 0;
}
