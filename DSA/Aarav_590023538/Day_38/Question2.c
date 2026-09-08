#include <stdio.h>
#include <stdlib.h>

java
import java.util.*;

class Solution {
    public int[] deckArrangement(int n) {
        int[] result = new int[n];
        Deque<Integer> positions = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            positions.addLast(i);
        }
        
        int value = 1;
        while (!positions.isEmpty()) {
            // Reveal the position at the front
            int pos = positions.pollFirst();
            result[pos] = value++;
            
            // Move next position to the bottom
            if (!positions.isEmpty()) {
                positions.addLast(positions.pollFirst());
            }
        }
        
        return result;
    }
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
