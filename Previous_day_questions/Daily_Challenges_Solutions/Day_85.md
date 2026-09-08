<h2 align="center">Week 13 Day 85 (07/09/2026)</h2>

## 1. Assign Cookies (LeetCode #455)
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0;
    int cookie = 0;

    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child])
            child++;

        cookie++;
    }

    return child;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];

    cout << findContentChildren(g, s) << "\n";
    return 0;
}
```

* Time: O(n log n + m log m) — sorting the greed factors and cookie sizes dominates the runtime.
* Space: O(1) extra space apart from the space used internally by sorting.

The optimized greedy approach sorts both arrays and uses two pointers. Always try to satisfy the child with the smallest greed factor using the smallest available cookie that is large enough. If a cookie is too small, it cannot satisfy the current child or any child with a larger greed factor, so it is skipped.

**Optimized solution:** Sorting followed by the two-pointer greedy approach is optimal for this problem. It maximizes the number of content children while avoiding unnecessary assignments.

**Inbuilt function:** `std::sort()` from the `<algorithm>` header is used to sort both arrays efficiently.

---

## 2. Maximum Number of Activities
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

int maxActivities(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> activities;

    for (int i = 0; i < n; i++)
        activities.push_back({end[i], start[i]});

    sort(activities.begin(), activities.end());

    int count = 1;
    int lastEnd = activities[0].first;

    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastEnd) {
            count++;
            lastEnd = activities[i].first;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++)
        cin >> start[i];

    for (int i = 0; i < n; i++)
        cin >> end[i];

    cout << maxActivities(start, end) << "\n";
    return 0;
}
```

* Time: O(n log n) — sorting the activities by their ending times dominates the runtime.
* Space: O(n) — a vector of activity pairs is used to store the start and end times together.

The greedy approach selects activities in increasing order of their finishing times. After selecting an activity, the next activity is chosen only if its start time is greater than or equal to the ending time of the previously selected activity. Choosing the activity that finishes earliest always leaves the maximum possible time available for future activities.

**Optimized solution:** The earliest-finish-time greedy strategy is the standard optimal solution for maximizing the number of non-overlapping activities. Sorting is required to process activities in the correct order.

**Inbuilt function:** `std::sort()` from the `<algorithm>` header is used to arrange the activities by their ending times.

---
