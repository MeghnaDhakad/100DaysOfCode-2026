#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to compare two strings after processing backspaces
bool backspaceCompare(char s[], char t[])
{
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    int skipS = 0;
    int skipT = 0;

    // Traverse both strings from the end
    while (i >= 0 || j >= 0)
    {
        // Find the next valid character in s
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skipS++;
                i--;
            }
            else if (skipS > 0)
            {
                skipS--;
                i--;
            }
            else
            {
                break;
            }
        }

        // Find the next valid character in t
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                skipT++;
                j--;
            }
            else if (skipT > 0)
            {
                skipT--;
                j--;
            }
            else
            {
                break;
            }
        }

        // Compare the current valid characters
        if (i >= 0 && j >= 0)
        {
            if (s[i] != t[j])
                return false;
        }
        else if (i >= 0 || j >= 0)
        {
            // One string still has characters left
            return false;
        }

        i--;
        j--;
    }

    return true;
}

int main()
{
    char s[201], t[201];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    if (backspaceCompare(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
