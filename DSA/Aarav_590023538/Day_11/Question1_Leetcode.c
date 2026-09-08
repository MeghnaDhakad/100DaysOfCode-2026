#include <stdio.h>
#include <stdlib.h>

python
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # Dictionaries to store the last occurrence of characters
        first = {}
        second = {}
        # Traverse both strings
        for i in range(len(s)):
            # If previous occurrences are different
            if first.get(s[i], 0) != second.get(t[i], 0):
                return False
            # Store current position (+1 because default value is 0)
            first[s[i]] = i + 1
            second[t[i]] = i + 1
        return True

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
