<h2 align="center">Week 13 Day 88 (10/09/2026)</h2>

## 1. Array Partition (LeetCode #561)
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int sum = 0;

    for (int i = 0; i < nums.size(); i += 2)
        sum += nums[i];

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(2 * n);

    for (int i = 0; i < 2 * n; i++)
        cin >> nums[i];

    cout << arrayPairSum(nums) << "\n";
    return 0;
}
```

* Time: O(n log n) — sorting the array dominates the runtime.
* Space: O(1) extra space apart from the space used internally by sorting.

The greedy approach sorts the numbers and pairs adjacent elements. After sorting, the smaller element of every adjacent pair is selected for the sum. Pairing adjacent numbers minimizes the loss caused by larger numbers being paired with much smaller numbers.

**Optimized solution:** Sorting followed by summing every alternate element is the standard optimal greedy solution for this problem.

**Inbuilt function:** `std::sort()` from the `<algorithm>` header is used to sort the array efficiently.

---

## 2. Job Sequencing with Deadlines
### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline;
    long long profit;
};

bool compare(Job& a, Job& b) {
    return a.profit > b.profit;
}

int find(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

long long maxProfit(vector<int>& deadline, vector<long long>& profit) {
    int n = deadline.size();
    vector<Job> jobs(n);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        jobs[i] = {deadline[i], profit[i]};
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<int> parent(maxDeadline + 1);

    for (int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    long long totalProfit = 0;

    for (Job& job : jobs) {
        int availableSlot = find(parent, job.deadline);

        if (availableSlot > 0) {
            totalProfit += job.profit;
            parent[availableSlot] = find(parent, availableSlot - 1);
        }
    }

    return totalProfit;
}

int main() {
    int n;
    cin >> n;

    vector<int> deadline(n);
    vector<long long> profit(n);

    for (int i = 0; i < n; i++)
        cin >> deadline[i];

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << maxProfit(deadline, profit) << "\n";
    return 0;
}
```

* Time: O(n log n) — sorting the jobs by profit dominates the runtime, while disjoint-set operations are nearly constant time.
* Space: O(n + d) — arrays are used to store the jobs and available time slots, where `d` is the maximum deadline.

The greedy approach processes jobs in decreasing order of profit and schedules each job in the latest available slot before its deadline. This preserves earlier slots for jobs with tighter deadlines while prioritizing higher-profit jobs.

**Optimized solution:** The disjoint-set approach efficiently finds the latest available slot for each job, avoiding repeated backward scanning of time slots. This gives an optimized `O(n log n)` solution dominated by sorting.

**Inbuilt function:** `std::sort()` from the `<algorithm>` header is used to arrange the jobs in decreasing order of profit.

---
