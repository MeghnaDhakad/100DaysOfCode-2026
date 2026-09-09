#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
    // Sort denominations in descending order to pick the largest first
    sort(coins.rbegin(), coins.rend());
    
    int count = 0;
    
    for (int coin : coins) {
        if (amount == 0) break; // Stop early if we've made exact change
        
        if (coin <= amount) {
            // Add how many of this coin we can use
            count += amount / coin;
            // Update the remaining amount to be made
            amount %= coin; 
        }
    }
    
    return count;
}

int main() {
    vector<int> coins = {1, 5, 10, 25, 50};
    int amount = 87;
    
    cout << "Output: " << minCoins(coins, amount) << "\n";
    // Expected Output: 5 (One 50, one 25, one 10, two 1s)
    
    return 0;
}