#include <stdio.h>
#include <stdlib.h>

python
# Input string
s = input()
# Store all distinct characters of the string
distinct_chars = set(s)
# Total distinct characters required
total_distinct = len(distinct_chars)
# Initialize answer with maximum possible length
answer = len(s)
# Check every possible substring
for i in range(len(s)):
    # Store distinct characters in the current substring
    current = set()
    for j in range(i, len(s)):
        # Add current character
        current.add(s[j])
        # If all distinct characters are present
        if len(current) == total_distinct:
            # Update minimum length
            if (j - i + 1) < answer:
                answer = j - i + 1
            # No need to expand this substring further
            break
# Print the length of the smallest valid substring
print(answer)

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
