<h2 align="center">Week 13 Day 87 (09/09/2026)</h2>

## 1. Lemonade Change (LeetCode #860)
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } 
        else if (bill == 10) {
            if (five == 0)
                return false;

            five--;
            ten++;
        } 
        else {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } 
            else if (five >= 3) {
                five -= 3;
            } 
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> bills(n);

    for (int i = 0; i < n; i++)
        cin >> bills[i];

    cout << (lemonadeChange(bills) ? "true" : "false") << "\n";
    return 0;
}
```

* Time: O(n) — each customer's bill is processed exactly once.
* Space: O(1) — only counters for `$5` and `$10` bills are maintained.

The greedy approach always tries to preserve as many `$5` bills as possible. For a `$20` bill, giving one `$10` bill and one `$5` bill as change is preferred over giving three `$5` bills because `$5` bills are more flexible for future transactions.

**Optimized solution:** The single-pass greedy approach is optimal because each transaction must be processed in the given order.

**Inbuilt function:** No special inbuilt function is required. Simple counters are sufficient to track the available change.

---

## 2. Minimum Number of Coins
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

long long minimumCoins(vector<long long>& coins, long long amount) {
    sort(coins.rbegin(), coins.rend());

    long long count = 0;

    for (long long coin : coins) {
        if (coin <= amount) {
            count += amount / coin;
            amount %= coin;
        }
    }

    return amount == 0 ? count : -1;
}

int main() {
    int n;
    cin >> n;

    vector<long long> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    long long amount;
    cin >> amount;

    cout << minimumCoins(coins, amount) << "\n";
    return 0;
}
```

* Time: O(n log n) — sorting the coin denominations dominates the runtime.
* Space: O(1) extra space apart from the space used internally by sorting.

The greedy approach always selects the largest denomination that does not exceed the remaining amount. After taking as many coins of that denomination as possible, the process continues with the next smaller denomination.

**Optimized solution:** Under the problem's guarantee that the given coin system is one for which greedy selection is optimal, this approach produces the minimum possible number of coins.

**Inbuilt function:** `std::sort()` from the `<algorithm>` header is used to arrange the coin denominations in descending order.

---
