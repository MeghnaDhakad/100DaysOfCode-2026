#include <stdio.h>
#include <stdlib.h>

python
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # Convert banned words into a set for faster lookup
        banned = set(banned)

        # Remove punctuation from the paragraph
        for ch in string.punctuation:
            paragraph = paragraph.replace(ch, " ")

        # Convert to lowercase and split into words
        words = paragraph.lower().split()

        # Dictionary to store frequency of each word
        freq = {}

        # Count frequency of non-banned words
        for word in words:
            if word not in banned:
                if word in freq:
                    freq[word] += 1
                else:
                    freq[word] = 1

        # Find the most frequent non-banned word
        answer = ""
        max_count = 0

        for word in freq:
            if freq[word] > max_count:
                max_count = freq[word]
                answer = word

        return answer

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
