<h2 align="center">Week 13 Day 86 (08/09/2026)</h2>

## 1. Longest Palindrome (LeetCode #409)
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    int freq[128] = {0};

    for (char ch : s)
        freq[ch]++;

    int length = 0;
    bool hasOdd = false;

    for (int count : freq) {
        length += (count / 2) * 2;

        if (count % 2 == 1)
            hasOdd = true;
    }

    return length + hasOdd;
}

int main() {
    string s;
    cin >> s;

    cout << longestPalindrome(s) << "\n";
    return 0;
}
```

* Time: O(n) — the string is traversed once to count character frequencies and the frequency array has constant size.
* Space: O(1) — a fixed-size frequency array is used.

The greedy approach uses all possible pairs of characters because every pair can be placed symmetrically on both sides of the palindrome. If at least one character has an odd frequency, one extra character can be placed at the center.

**Optimized solution:** Counting character frequencies and using every possible pair is optimal because each character only needs to be processed a constant number of times.

**Inbuilt function:** No sorting or special inbuilt function is required. A fixed-size frequency array provides an efficient solution.

---

## 2. Fractional Knapsack
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long value;
    long long weight;
};

double fractionalKnapsack(vector<Item>& items, long long capacity) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (long double)a.value / a.weight >
               (long double)b.value / b.weight;
    });

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity == 0)
            break;

        if (item.weight <= capacity) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += (double)item.value * capacity / item.weight;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int n;
    cin >> n;

    vector<long long> value(n), weight(n);

    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    long long capacity;
    cin >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++)
        items[i] = {value[i], weight[i]};

    cout << fractionalKnapsack(items, capacity) << "\n";
    return 0;
}
```

* Time: O(n log n) — sorting the items by their value-to-weight ratio dominates the runtime.
* Space: O(n) — a vector of items is used to store the value and weight together.

The greedy approach sorts all items by decreasing value-to-weight ratio and takes the highest-value-per-unit-weight items first. If the remaining capacity cannot hold an entire item, only the required fraction is taken.

**Optimized solution:** Sorting by value-to-weight ratio and greedily taking as much as possible from each item is the standard optimal solution for the fractional knapsack problem.

**Inbuilt function:** `std::sort()` from the `<algorithm>` header is used with a custom comparator to arrange items by decreasing value-to-weight ratio.

---
