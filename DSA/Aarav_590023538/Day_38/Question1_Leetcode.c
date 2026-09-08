#include <stdio.h>
#include <stdlib.h>

java
import java.util.*;

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] count = new int[2]; // count[0] = students wanting circular, count[1] = students wanting square
        for (int s : students) {
            count[s]++;
        }
        
        int i = 0; // pointer into sandwiches stack
        while (i < sandwiches.length) {
            int type = sandwiches[i];
            if (count[type] == 0) {
                // No student left wants this sandwich type -> rest are stuck
                break;
            }
            count[type]--;
            i++;
        }
        
        return count[0] + count[1];
    }
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
