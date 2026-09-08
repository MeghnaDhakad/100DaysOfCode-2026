#include <stdio.h>
#include <stdlib.h>

java
import java.util.*;

class Solution {
    public List<Integer> findAnagrams(String log, String pattern) {
        List<Integer> result = new ArrayList<>();
        int n = log.length(), m = pattern.length();
        if (m > n) return result;

        int[] patternCount = new int[26];
        int[] windowCount = new int[26];

        for (int i = 0; i < m; i++) {
            patternCount[pattern.charAt(i) - 'a']++;
            windowCount[log.charAt(i) - 'a']++;
        }

        if (Arrays.equals(patternCount, windowCount)) {
            result.add(0);
        }

        for (int i = m; i < n; i++) {
            windowCount[log.charAt(i) - 'a']++;
            windowCount[log.charAt(i - m) - 'a']--;

            if (Arrays.equals(patternCount, windowCount)) {
                result.add(i - m + 1);
            }
        }

        return result;
    }
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
