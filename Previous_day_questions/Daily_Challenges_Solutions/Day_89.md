<h2 align="center">Week 13 Day 89 (11/09/2026)</h2>

## 1. Can Place Flowers (LeetCode #605)
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();

    for (int i = 0; i < size && n > 0; i++) {
        if (flowerbed[i] == 0 &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i == size - 1 || flowerbed[i + 1] == 0)) {

            flowerbed[i] = 1;
            n--;
        }
    }

    return n == 0;
}

int main() {
    int m, n;
    cin >> m;

    vector<int> flowerbed(m);
    for (int i = 0; i < m; i++)
        cin >> flowerbed[i];

    cin >> n;

    cout << (canPlaceFlowers(flowerbed, n) ? "true" : "false") << "\n";
    return 0;
}
```

* Time: O(n) — the flowerbed is traversed at most once.
* Space: O(1) extra space — apart from the input array, only a few variables are used.

The greedy approach checks every plot from left to right. Whenever an empty plot has no flower on either side, a flower is planted immediately. This local choice is optimal because planting at the earliest valid position cannot reduce the number of flowers that can be planted later.

**Optimized solution:** The single-pass greedy traversal is optimal because every plot may need to be inspected at least once, giving O(n) time complexity.

**Inbuilt function:** No special inbuilt function is required. The solution uses direct array traversal and conditional checks.

---

## 2. Buy Two Chocolates
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

int buyChoco(vector<int>& prices, int money) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int price : prices) {
        if (price < first) {
            second = first;
            first = price;
        } else if (price < second) {
            second = price;
        }
    }

    int cost = first + second;

    if (cost <= money)
        return money - cost;

    return money;
}

int main() {
    int n, money;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cin >> money;

    cout << buyChoco(prices, money) << "\n";
    return 0;
}
```

* Time: O(n) — the array is traversed once to find the two cheapest chocolates.
* Space: O(1) extra space — only two variables are used to track the smallest prices.

The optimized greedy approach keeps track of the smallest and second-smallest chocolate prices while traversing the array. After finding the two cheapest chocolates, their total cost is compared with the available money. This avoids sorting the entire array.

**Optimized solution:** The one-pass approach is optimal because finding the two minimum values requires inspecting each price at least once. It improves on the sorting approach, which would take O(n log n) time.

**Inbuilt function:** An alternative approach is to use `std::sort()` from the `<algorithm>` header and add the first two elements, but that takes O(n log n) time. The one-pass approach above is more efficient.
