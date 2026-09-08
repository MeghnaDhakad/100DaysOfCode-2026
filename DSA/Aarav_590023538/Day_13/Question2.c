#include <stdio.h>
#include <stdlib.h>

python
# Function to count all distinct subsequences
def countSubsequences(s):
    # Store all distinct subsequences in a set
    subsequences = {""}
    # Traverse each character of the string
    for ch in s:
        new_subsequences = set()
        # Append the current character to every existing subsequence
        for sub in subsequences:
            new_subsequences.add(sub + ch)
        # Add the newly formed subsequences to the set
        subsequences.update(new_subsequences)
    # Return the total number of distinct subsequences
    return len(subsequences)

# Function to determine the better string
def betterString(s1, s2):
    # Count distinct subsequences of both strings
    count1 = countSubsequences(s1)
    count2 = countSubsequences(s2)
    # Return s1 if it has more or equal distinct subsequences
    if count1 >= count2:
        return s1
    else:
        return s2

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
