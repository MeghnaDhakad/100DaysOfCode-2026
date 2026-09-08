#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        // Array to count frequencies of all ASCII characters
        int counts[128] = {0};
        for (char c : s) {
            counts[c]++;
        }
        
        int maxLength = 0;
        bool hasOdd = false;
        
        for (int count : counts) {
            // Add the largest even number less than or equal to count
            maxLength += (count / 2) * 2;
            
            // Flag if there is at least one character with an odd count
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }
        
        // If we found any odd-frequency character, we can put one in the middle
        return hasOdd ? maxLength + 1 : maxLength;
    }
};