#include <stdio.h>
#include <stdlib.h>

python
class Solution:
    def solve(self, s: str) -> str:
        ans = ""

        # Traverse each character of the string
        for ch in s:
            # Convert uppercase letter to lowercase
            ch = ch.lower()

            # Check if the character is not a vowel
            if ch != 'a' and ch != 'e' and ch != 'i' and ch != 'o' and ch != 'u':
                # Add '.' before every consonant
                ans = ans + "." + ch

        return ans


# Input string
s = input("Enter the string: ")

# Create object and print the result
obj = Solution()
print("Output:", obj.solve(s))

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
