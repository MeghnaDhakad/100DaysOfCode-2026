#include <iostream>
#include <vector>

using namespace std;

int buyChoco(const vector<int>& prices, int money) {
    int min1 = 1e9; // Represents infinity (or a sufficiently large number)
    int min2 = 1e9;
    
    // Find the two smallest elements in a single pass
    for (int price : prices) {
        if (price < min1) {
            min2 = min1;   // The old minimum becomes the second minimum
            min1 = price;  // Update the new absolute minimum
        } else if (price < min2) {
            min2 = price;  // Update the second minimum
        }
    }
    
    int cost = min1 + min2;
    
    // Check if we can afford the two cheapest chocolates
    if (cost <= money) {
        return money - cost;
    }
    
    // If not, keep all the money
    return money;
}

int main() {
    vector<int> prices = {1, 2, 2};
    int money = 3;
    
    cout << "Output: " << buyChoco(prices, money) << "\n";
    // Expected Output: 0 (Cost is 1 + 2 = 3, remaining is 3 - 3 = 0)
    
    return 0;
}