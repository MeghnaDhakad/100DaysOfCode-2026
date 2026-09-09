#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                // Greedily prefer handing out a $10 and a $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                // Fallback to handing out three $5s
                else if (five >= 3) {
                    five -= 3;
                } 
                // Cannot make change
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};