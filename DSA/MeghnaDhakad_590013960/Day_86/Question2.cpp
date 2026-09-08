#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to bind an item's properties together
struct Item {
    int value;
    int weight;
};

// Comparator to sort by value/weight ratio in descending order
bool compareItems(const Item& a, const Item& b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int capacity, const vector<int>& values, const vector<int>& weights) {
    int n = values.size();
    vector<Item> items(n);
    
    for (int i = 0; i < n; i++) {
        items[i] = {values[i], weights[i]};
    }
    
    // Sort items greedily by their ratio
    sort(items.begin(), items.end(), compareItems);
    
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take the fractional part to fill the remaining capacity
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    
    cout << "Output: " << fractionalKnapsack(capacity, values, weights) << "\n";
    // Expected Output: 240
    
    return 0;
}