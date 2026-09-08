#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    // Read the string
    scanf("%s", s);

    // Find the length of the string
    int n = strlen(s);

    // Reverse the string by swapping characters
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }

    // Print the reversed string
    printf("%s\n", s);

    return 0;
}
