#include <stdio.h>
#include <stdlib.h>

python
class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        # Initially, one line is being used
        lines = 1
        # Current width occupied in the current line
        current_width = 0
        # Traverse each character in the string
        for ch in s:
            # Find the width of the current character
            width = widths[ord(ch) - ord('a')]
            # If the character fits in the current line
            if current_width + width <= 100:
                current_width += width
            # Otherwise, move to a new line
            else:
                lines += 1
                current_width = width
        # Return total lines and width of the last line
        return [lines, current_width]

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
