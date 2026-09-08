#include <stdio.h>

int main() {
    char str[1000];
    int i = 0, j = 0;

    // Read the complete string including spaces
    fgets(str, sizeof(str), stdin);

    // Traverse the string
    while (str[i] != '\0') {
        // Copy only non-space characters
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }

    // Add null character at the end
    str[j] = '\0';

    // Print the modified string
    printf("%s", str);

    return 0;
}
