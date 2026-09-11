#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Early exit if no flowers need to be planted
        if (n == 0) return true;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty
            if (flowerbed[i] == 0) {
                // Ensure left and right boundaries are respected
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    // Plant a flower here
                    flowerbed[i] = 1; 
                    n--;
                    
                    // If we've planted all required flowers, we're done
                    if (n == 0) return true;
                }
            }
        }
        
        return n <= 0;
    }
};